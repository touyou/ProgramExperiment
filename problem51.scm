(define (my-reverse-iter l acc)
  (if (null? l)
      acc
      (my-reverse-iter (cdr l) (cons (car l) acc))))
(define (my-reverse l) (my-reverse-iter l '()))
