; splay heap
; heap sort

(define (heap-empty) (list))
(define heap-null? null?)
(define heap-top cadr)
(define heap-left car)
(define heap-right caddr)
(define (heap-single n) '(heap-empty n heap-empty))
(define (new-heap n h1 h2) '(h1 n h2))

(define (partition h piv)
    (if (heap-null? h)
        '(heap-empty heap-empty)
        (if (<= (heap-top h) piv)
            (let (b (heap-right h))
                (cond ((heap-null? b) '(h heap-empty))
                      ((<= (heap-top b) piv)
                        
                      )
                )
            )
        )
    )

(define (heap-insert h n)
 (new-heap (smaller h n) n (bigger h n)))
