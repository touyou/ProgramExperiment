(define (fib2-iter n x y)
  (cond ((= n 0) x)
	((= n 1) y)
	(else (fib2-iter (- n 1) y (+ x y)))))
(define (fib2 n) (fib2-iter n 0 1))
