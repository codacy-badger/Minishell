# Minishell [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)


An implementation of some a simple start of a **shellscript** [a 42 project].

This project aims to get familiar with some of the core of the Unix system and explore an important part of the system’s API: process creation and synchronisation.

It implies to code in the cleanest and simplest manner


## Description



## Architecture

The following is the main steps in the minishell workflow:

- Input Stream

- Lexical Analysis

- Parsing

- Dispatcher

- Dispatcher

## General Architecture

```mermaid
graph LR
subgraph pool
	subgraph earn
	Sa0((start))
	Sa1(work)
Sa2((receive wage))

	Sa0-->Sa1
	Sa1-->Sa2
	Sa2-->Sa1
	end

	Sa2-.->S0

	subgraph spend
	S0((start))
S2(Go shopping)
	S3{How much money will I spend?} 
	S1(save for later)
	S4(buy Laptop)
	S5(buy iPhone)
S6(buy Car)
	S7{ }
S8((end))
	S9{ }
S10(pay)

	S0-->S2
	S2 --> S3
	S3-->| =0 | S1
	S3-->| <= 1k | S4
	S3 -->| > 1k| S5
	S3 -->| >10k | S6
	S1-->S9
	S4-->S7
	S5-->S7
	S6-->S7
	S7-->S10
	S10-->S9
	S9-->S8
	end
	end
	```


## Lexical Analysis

	After the input stream has been capture. A raw string is passed to `function` for a lexical analysis. A process of tokenization takes place.

	>Each token is stored in a node of a linked-list.
	> Each token will be executed in a fork or as a builtin after been dispatched.

	Linked-list containing the tokens :
	```mermaid
	graph LR
	Command1-->Command2
	subgraph Command1
	Command1
	a2
	end
	subgraph Command2
	Command2
	b2
	end
	```


	And this will produce a flow chart:

	```mermaid
	graph LR

Main(main)

	A[Square Rect] -- Link text --> B((Circle))
A --> C(Round Rect)
	B --> D{Rhombus}
	C --> D
	```


