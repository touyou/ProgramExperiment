(define (if-fun exp1 exp2 exp3)
  (if exp1 exp2 exp3))
(define (fact4-iter n acc)
  (if-fun (= n 0)
	  acc
	  (fact4-iter (- n 1) (* acc n))))
(define (fact4 n) (fact4-iter n 1))
