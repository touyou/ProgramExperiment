(define (my-gcd a b)
	(if (= 0 (modulo a b))
	    b
	    (my-gcd b (modulo a b))))