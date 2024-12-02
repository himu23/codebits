import numpy as np

def objective_function(x): return np.sum(x**2)

num_particles, dimensions, max_iter = 30, 2, 1000
w_max, w_min, c1, c2 = 0.9, 0.4, 2.0, 2.0
lb, ub = -10, 10

positions = np.random.uniform(low=lb, high=ub, size=(num_particles, dimensions))
velocities = np.random.uniform(low=-1, high=1, size=(num_particles, dimensions))

personal_best_positions = np.copy(positions)
personal_best_scores = np.array([objective_function(p) for p in positions])
global_best_position = personal_best_positions[np.argmin(personal_best_scores)]
global_best_score = np.min(personal_best_scores)

for t in range(max_iter):
    w = w_max - (w_max - w_min) * (t / max_iter)
    r1, r2 = np.random.rand(), np.random.rand()
    velocities = (w * velocities + c1 * r1 * (personal_best_positions - positions) + c2 * r2 * (global_best_position - positions))
    positions = np.clip(positions + velocities, lb, ub)
    scores = np.array([objective_function(p) for p in positions])
    
    for i in range(num_particles):
        if scores[i] < personal_best_scores[i]:
            personal_best_scores[i], personal_best_positions[i] = scores[i], positions[i]
    
    if np.min(scores) < global_best_score:
        global_best_score = np.min(scores)
        global_best_position = positions[np.argmin(scores)]
    
    if t % 100 == 0:
        print(f"Iteration {t}/{max_iter}, Global Best Score: {global_best_score}")

print("Optimized result:", global_best_position, "with score:", global_best_score)
