intersection-of-multiple-insertion-and-deletion-balls
This project provides an algorithms for producing the intersection of multiple deletion and insertion balls.
Given k words of length n-t and k words of length n+t, the results are all words of length n that are subsequences of the long words and supersequences of the short words.
There are two main algorithms:
Algorithm 1:
A naive approach for calculating the intersection.
Each word of length n+t is paired with a word of length n-t and the intersection of their t-deletion and t-insersion balls respectively is calculated. We then intersect the k sets and return the intersection as the result.

Algorithm 2:
A pair of words, one of length n+t and one of length n-t, are chosen according to some heuristic.
The intersection of their t-deletion and t-insertion balls respectively is calculated. The algorithm then proceeds with checking for every word in the intersection if it is a subsequence of all of the reamining long sequences and a supersequence of all remaining subsequences. only words that satisfy all of these conditions is outputed as part of the final reseult.
Heuristics can be found in the heuristics.cpp file. We reccomend using heuristic... which outperforms the rest.
It worls as follows: the word of length n+t that is chosen is the one with the smallest number of runs. The word of length n-t that is chosen is the one with the largest number of runs. Ties are broken by the choosing the first word that satisfies the condition. We reccomend using this option.

Both algorithms rely on the ability to calculate the intersection of a t-deletion ball of a word of length n+t and a t-insertion ball of a word of length n-t. This is done using the class CommonSequences whose algorithm is based on those presented in the paper.....



Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

Prerequisites
What things you need to install the software and how to install them

Give examples
Installing
A step by step series of examples that tell you how to get a development env running

Say what the step will be

Give the example
And repeat

until finished
End with an example of getting some data out of the system or using it for a little demo



Running the tests
A python file... is provided for running tests
The test should in the follwoing format:
....


Break down into end to end tests
Explain what these tests test and why

Give an example
And coding style tests
Explain what these tests test and why

Give an example
Deployment
Add additional notes about how to deploy this on a live system

Built With
Dropwizard - The web framework used
Maven - Dependency Management
ROME - Used to generate RSS Feeds
Contributing
Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.

Versioning
We use SemVer for versioning. For the versions available, see the tags on this repository.

Authors
Billie Thompson - Initial work - PurpleBooth
See also the list of contributors who participated in this project.

License
This project is licensed under the MIT License - see the LICENSE.md file for details

Acknowledgments
Hat tip to anyone whose code was used
Inspiration
etc