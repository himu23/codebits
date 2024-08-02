#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int songId;
    Node* prev;
    Node* next;
    
    Node(int id) : songId(id), prev(nullptr), next(nullptr) {}
};

class MusicPlayer {
private:
    Node* head;
    Node* currentsong;

public:
    MusicPlayer() : head(nullptr), currentsong(nullptr) {}

    // Function to add a song to the end of the list
    void addSong(int songId) {
       Node* newnode= new Node(songId);
       if(head==nullptr){
           head=newnode;
           currentsong=newnode;
           return;
       }
       Node* temp=head;
       while(temp -> next != nullptr){
           temp= temp->next;
       }
       temp->next=newnode;
       newnode->prev=temp;
    }

    // Function to play the next song
    void playNext() {
        if(currentsong -> next != nullptr){
            currentsong=currentsong->next;
        }
    }

    // Function to play the previous song
    void playPrev() {
       if(currentsong->prev != nullptr){
           currentsong=currentsong->prev;
       }
    }

    // Function to switch to a specific song
    void switchSong(int songId) {
        Node* temp=head;
        while(temp != nullptr){
            if(temp->songId == songId){
                currentsong=temp;
                return;
            }
        }
        temp=temp->next;
     
    }

    // Function to return the songId of the current song playing
    int current() {
      return currentsong->songId;
    }
};

int main() {
    MusicPlayer player;
    int query, songId;
    int q;
    cin >> q;
    while (q--) {
        cin >> query;

        switch (query) {
            case 1:
                cin >> songId;
                player.addSong(songId);
                break;
            case 2:
                player.playNext();
                break;
            case 3:
                player.playPrev();
                break;
            case 4:
                cin >> songId;
                player.switchSong(songId);
                break;
            case 5:
                cout << player.current() << endl;
                break;
            default:
                cout << "Invalid query!" << endl; 
        }
    }

    return 0;
}
