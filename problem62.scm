(define (empty-frame)
  (list))
(define (update frame var val)
  (cons (cons var val) frame))
(define (lookup var frame)
  (assoc var frame))
(define (make-env)
  (list (empty-frame)))
(define (extend-env env)
  (cons (empty-frame) env))
(define (define-var! env var val)
  (if (null? env)
    env
    (cons (update (car env) var val) (cdr env))))
(define (lookup-var var env)
  (if (null? env)
    #f
    (let ((found (lookup var (car env))))
        (if (pair? found)
          found
          (lookup-var var (cdr env))))))
(define (make-top-env)
  ;; make top env?
  )


(define (scheme)
  (let ((top-env (make-top-env)))
    (define (rep-loop env)
      (display "sister> ")
      (let* ((res (base-eval env (read)))
             (env (car res))
             (val (cdr res)))
        (print-data val)
        (newline)
        (if (equal? val '*exit*)
            #t
            (rep-loop env))))
    (rep-loop top-env)))
