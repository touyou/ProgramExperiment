(define (fact2-iter n acc)
  (if (= n 0)
      acc
      (fact2-iter (- n 1) (* acc n))))
(define (fact2 n) (fact2-iter n 1))
