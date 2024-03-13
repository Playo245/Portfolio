% Predicates to calculate factorial and sum of digits
factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, SubResult),
    Result is N * SubResult.

sum_of_digits(0, 0).
sum_of_digits(Number, Sum) :-
    Number > 0,
    Digit is Number mod 10,
    RemainingDigits is Number // 10,
    sum_of_digits(RemainingDigits, SubSum),
    Sum is SubSum + Digit.

% Main predicate to find the sum of digits in the factorial of the given number
find_sum_of_digits(N) :-
    factorial(N, Factorial),
    sum_of_digits(Factorial, Result),
    write(Result), nl.

% Entry point for command line input
:- initialization(main).

main :-
    current_prolog_flag(argv, Argv),
    % Check if there is at least one command line argument
    (   append(_, [N|_], Argv),
        atom_number(N, NValue),
        integer(NValue)
    ->  find_sum_of_digits(NValue),
        halt
    ;   write('Usage: swipl -s test.pl -- <integer>'), nl,
        halt(1)
    ).
