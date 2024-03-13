% Ensures that main is called at startup
:- initialization(main, main).

% Entry point of the program
main :-
    % Retrieves command line arguments
    current_prolog_flag(argv, Args),
    % Converts arguments from string to numbers
    maplist(atom_number, Args, [First, Last]),
    % Calls the main logic with the parsed arguments
    square_remainders(First, Last, Sum),
    % Prints the result
    format('~d~n', [Sum]),
    % Exits the program
    halt.

% Calculates the sum of maximum remainders within a given range
% First: Starting value of range
% Last: Ending value of range
% Sum: The calculated sum of maximum remainders
square_remainders(First, Last, Sum) :-
    % Finds all remainders for each value in the range and stores them in Rems
    findall(Rem, (between(First, Last, A), max_remainder(A, Rem)), Rems),
    % Sums up all the remainders
    sum_list(Rems, Sum).

% Calculates the maximum remainder for a given value of 'a'
% A: The current value for which the maximum remainder is calculated
% MaxRem: The maximum remainder found for 'a'
max_remainder(A, MaxRem) :-
    % Defines the upper bound for the loop (2 * A)
    UpperBound is 2 * A,
    % Finds all remainders for 'a' using different values of 'n' and stores them in Rems
    findall(Rem, (between(1, UpperBound, N), remainder(A, N, Rem)), Rems),
    % Finds the maximum value in the list of remainders
    max_list(Rems, MaxRem).

% Calculates the remainder for a given 'a' and 'n'
% A: The base value
% N: The exponent value
% Rem: The calculated remainder
remainder(A, N, Rem) :-
    % Modular exponentiation for (A - 1)^N mod A^2
    mod_exp(A - 1, N, A * A, Term1),
    % Modular exponentiation for (A + 1)^N mod A^2
    mod_exp(A + 1, N, A * A, Term2),
    % Calculating the remainder for the sum of Term1 and Term2
    Rem is (Term1 + Term2) mod (A * A).

% Efficiently calculates (Base^Exponent) mod Modulus
% Base: The base of the expression
% Exponent: The exponent of the expression
% Modulus: The modulus for the operation
% Result: The result of the modular exponentiation
mod_exp(Base, Exponent, Modulus, Result) :-
    % Helper predicate for modular exponentiation
    mod_exp_aux(Base, Exponent, Modulus, 1, Result).

% Helper predicate for mod_exp
% Handles the actual computation of modular exponentiation
mod_exp_aux(_, 0, _, Result, Result) :- !.
mod_exp_aux(Base, Exponent, Modulus, Temp, Result) :-
    % If Exponent is odd, multiply Temp by Base
    (   Exponent mod 2 =:= 1
    ->  Temp1 is (Temp * Base) mod Modulus
    ;   Temp1 is Temp
    ),
    % Square the base for the next iteration
    Base1 is (Base * Base) mod Modulus,
    % Halve the exponent for the next iteration
    Exponent1 is Exponent // 2,
    % Recursively call mod_exp_aux with updated values
    mod_exp_aux(Base1, Exponent1, Modulus, Temp1, Result).
