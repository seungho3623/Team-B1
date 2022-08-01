def solution(n, lost, reserve):
    n_reserve = set(reserve)-set(lost)
    n_lost = set(lost)-set(reserve)

    for i in n_reserve: 
        if i-1 in n_lost: 
            n_lost.remove(i-1) 
        elif i+1 in n_lost: 
            n_lost.remove(i+1)

    return n - len(n_lost)