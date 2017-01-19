;; enviroment
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
;; lambda closure
(define (make-closure env params body)
  (cons '*lambda* (cons env (cons params body))))
(define (data-closure? data)
  (and (pair? data) (equal? (car data) '*lambda*)))
(define closure-env cadr)
(define closure-params caddr)
(define closure-body cdddr)
;; primitive function
(define (make-primitive arity fun)
  (list '*primitive* arity fun))
(define (data-primitive? data)
  (and (pair? data) (equal? (car data) '*primitive*)))
(define primitive-arity cadr)
(define primitive-fun caddr)
;; utility
(define (print-data data)
  (cond ((data-closure? data) (display "#<closure>"))
        ((data-primitive? data) (display "#<primitive>"))
        ((equal? data '*unspecified*) (display "#<unspecified>"))
        ((equal? data '*error*) (display "#<error>"))
        ((equal? data '*exit*))
        (else (write data))))
(define (constant? exp)
  (or (boolean? exp) (number? exp) (string? exp)))
(define (base-eval env exp)
  (cond ((eof-object? exp) (cons env '*exit*))
        ((constant? exp) (cons env exp))
        ((symbol? exp) (var-eval env exp))
        ((not (pair? exp)) (eval-error env 'unknown-data exp))
        ((equal? (car exp) 'exit) (cons env '*exit*))
        ((equal? (car exp) 'define) (def-eval env exp))
        ((equal? (car exp) 'let) (let-eval env exp))
        ((equal? (car exp) 'letrec) (letrec-eval env exp))
        ((equal? (car exp) 'lambda) (lambda-eval env exp))
        ((equal? (car exp) 'if) (if-eval env exp))
        ((equal? (car exp) 'begin) (begin-eval env exp))
        ((equal? (car exp) 'quote) (quote-eval env exp))
        (else (app-eval env exp))))
(define (eval-error env type exp)
  (display "ERROR: ")
  (write type)
  (display ": ")
  (print-data exp)
  (newline)
  (cons env '*error*))
(define (correct-syntax? type exp) #t)
(define (let-eval env exp)
  (if (correct-syntax? 'let exp)
    (base-eval env (let->app exp))
    (eval-error env 'syntax-error exp)))
(define (let->app exp)
  (let ((decl (cadr exp))
       (body (cddr exp)))
    (cons (cons 'lambda (cons (map car decl) body))
          (map cadr decl))))
(define (def-eval env exp)
  (if (correct-syntax? 'define exp)
    (let* ((var (cadr exp))
           (res (base-eval env (caddr exp)))
           (env (car res))
           (val (cdr res)))
      (cons (define-var env var val) var))
    (eval-error env 'syntax-error exp)))
(define (var-eval env exp)
  (cdar (lookup-var exp env)))
(define (lambda-eval env exp)
  (if (correct-syntax? 'lambda exp)
    (cons env (make-closure env (cadr exp) (cddr exp)))
    (eval-error env 'syntax-error exp)))
(define (map-base-eval env el)
  (cons env
        (map (lambda (exp) (cdr (base-eval env exp))) el)))
(define (base-apply env fun args)
  (cond ((data-closure? fun)
        ;; task
        )
        ((data-primitive? fun)
          (if (or (not (number? (primitive-arity fun)))
                  (= (primitive-arity fun) (length args)))
            ((primitive-fun fun) env args)
            (eval-error env 'wrong-number-of-args fun)))
          (else
            (eval-error env 'non-function fun))))
(define (app-eval env exp)
  (if (correct-syntax? 'app exp)
    (let* ((l (map-base-eval env exp))
           (env (car l))
           (fun (cadr l))
           (args (cddr l)))
      (base-apply env fun args))
    (eval-error env 'syntax-error exp)))
(define (make-top-env)
  (let* ((env (make-env))
         (env
           (define-var env '=
             (make-primitive 2 (lambda (env args)
                                 (cons env (= (car args) (cadr args)))))))
         (env
           (define-var env '+
             (make-primitive 2 (lambda (env args)
                                 (cons env (+ (car args) (cadr args)))))))
         (env
           (define-var env '*
             (make-primitive 2 (lambda (env args)
                                 (cons env (* (car args) (cadr args)))))))
         (env
           (define-var env 'list
             (make-primitive #f (lambda (env args) (cons env args)))))
         (env
           (define-var env 'null?
             (make-primitive 1 (lambda (env args)
                                 (cons env (null? (car args)))))))
         (env
           (define-var env 'equal?
             (make-primitive 2 (lambda (env args)
                                 (cons env (equal? (car args) (cadr args)))))))
         (env
           (define-var env 'display
             (make-primitive
              1
              (lambda (env args)
                (display (car args))
                (cons env '*unspecified*)))))
         (env
           (define-var env 'load
             (make-primitive
               1
               (lambda (env args)
                 (with-input-from-file (car args)
                   (lambda ()
                     (define (re-loop env)
                       (let* ((res (base-eval env (read)))
                              (env (car res))
                              (val (cdr res)))
                         (if (equal? val '*exit*)
                             (cons env '*unspecified*)
                             (re-loop env))))
                     (re-loop env))))))))
  env))
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
    (let ((top-env (car (base-eval top-env '(load "preamble.scm")))))
    (rep-loop top-env))))
