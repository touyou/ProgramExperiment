; splay heap
; heap sort

(define (heap-empty) (list))
(define heap-null? null?)
(define heap-top cadr)
(define heap-left car)
(define heap-right caddr)
(define (heap-single n) '(heap-empty n heap-empty))
(define (new-heap n h1 h2) '(h1 n h2))

(define 

(define (heap-insert h n)
 (new-heap (smaller h n) n (bigger h n)))
