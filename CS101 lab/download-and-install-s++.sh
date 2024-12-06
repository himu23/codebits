#!/bin/bash
##########
# Written by Bhaskaran Raman, 21 Feb 2019
##########

INSTALLDIR=$HOME/simplecpp
BINDIR=$HOME/bin
TARFILE="simplecpp.tar"
URL="https://www.cse.iitb.ac.in/~ranade/simplecpp/$TARFILE"

if [ -d "$INSTALLDIR" ]; then
    echo "It looks like you already have simplecpp in $INSTALLDIR"
    echo "Remove $INSTALLDIR and rerun this script if you wish"
    exit 1
fi

if [ -f "$BINDIR/s++" ]; then
    echo "It looks like you already have s++ in $BINDIR"
    echo "Remove it and rerun this script if you wish"
    exit 2
fi

if [ -f "$BINDIR/runs++" ]; then
    echo "It looks like you already have runs++ in $BINDIR"
    echo "Remove it and rerun this script if you wish"
    exit 3
fi

function check_packages() {
    ##### Check if g++ and libx11-dev are there
    local to_install=""
    for pkg in "g++" "libx11-dev"
    do
	echo "Checking for package $pkg" 1>&2
	dpkg -l "$pkg" 1>&2
	res=$?
	if [ $res -eq 0 ]; then
	    echo "Package $pkg found" 1>&2
	else
	    echo "Package $pkg not found" 1>&2
	    to_install="$to_install $pkg"
	fi
    done
    echo "$to_install"
}

while true
do
    to_install=$(check_packages)
    echo "to_install is __${to_install}__"
    if [ -z "$to_install" ]; then
	echo "All required packages are present"
	break
    else
	echo "Attempting to install $to_install"
	sudo apt-get install $to_install
    fi
done

pushd /tmp
rm -f "$TARFILE"
echo "Downloading $TARFILE from $URL"
wget "$URL"
res=$?
if [ $res -ne 0 ]; then
    echo "Error in downloading $TARFILE from $URL, exiting"
    exit 10
fi
popd

pushd $HOME
echo "Attempting to untar"
tar xvf "/tmp/$TARFILE"
res=$?
popd
if [ $res -ne 0 ]; then
    echo "Untar failed, exiting"
    exit 4
fi
if [ ! -d "$INSTALLDIR" ]; then
    echo "$INSTALLDIR not found even after untarring, exiting"
    exit 5
fi

pushd "$INSTALLDIR"
echo "Compiling simplecpp"
./configure.sh
popd

if [ ! -x "$INSTALLDIR/s++" ]; then
    echo "s++ not found even after compilation, exiting"
    exit 6
fi

function print_spp() {
    echo "#!/bin/bash"
    echo "SPPDIR=$INSTALLDIR"
    echo "SPP=\$SPPDIR/s++"
    echo "\$SPP \$*"
}

function print_runspp() {
    echo "#!/bin/bash"
    echo "SPPDIR=$INSTALLDIR"
    echo "SPP=\$SPPDIR/s++"
    echo "EXEC=\"./a.out\""
    echo "rm -f \"\$EXEC\""
    echo "\$SPP \$*"
    echo "\$EXEC"
}

function print_dot_profile_spp() {
    echo "export PATH=\"$BINDIR:\$PATH\""
}

echo "Creating s++ and runs++ in $BINDIR"
mkdir -p "$BINDIR"
print_spp > "$BINDIR/s++"
print_runspp > "$BINDIR/runs++"
chmod +x "$BINDIR/s++" "$BINDIR/runs++"

echo "Adding $BINDIR to default path in .profile and .profile_spp"
rm -f "$HOME/.profile_spp"
print_dot_profile_spp > "$HOME/.profile_spp"
grep ".profile_spp" "$HOME/.bashrc"
res=$?
if [ $res -eq 0 ]; then
    echo "Your .bashrc already has the necessary PATH"
else
    echo "source \$HOME/.profile_spp" >> "$HOME/.bashrc"
fi

echo "Your environment is setup for using s++ and runs++"
echo "Open a new terminal or simply logout/login"
