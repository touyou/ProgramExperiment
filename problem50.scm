(define (my-assoc n l)
 (if (null? l)
    #f
    (if (equal? (car (car l)) n) 
     (car l) 
     (my-assoc n (cdr l)))))
