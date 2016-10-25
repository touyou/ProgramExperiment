(define min (lambda (a b) (if (< a b) a b)))
(define min-of-four (lambda (a b c d) (min (min a b) (min c d))))
