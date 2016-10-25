(define (even<odd? a b c d e)
	(< (length (filter even? (list a b c d e)))
	   (length (filter odd? (list a b c d e)))))
