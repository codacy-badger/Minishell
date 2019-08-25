# Minishell [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)
[![Build Status](https://travis-ci.com/Ant0wan/Minishell.svg?branch=master)](https://travis-ci.com/Ant0wan/Minishell)

An implementation of a tiny **shell** [a 42 project].

This project aims to get familiar with some of the core of the Unix system and explore an important part of the system’s API: process creation and synchronisation.

## Description

Minishell is organized in modules.

The following is the main steps in the minishell workflow:

- Input Stream

- Lexical Analysis

- Parsing

- Job control & execution

## Usage

- Clone repository
```shell=
git clone --recurse-submodules https://github.com/Ant0wan/Minishell.git
```

- Build minishell
```shell=
make -j
```

- Execute minishell
```shell=
./minishell
```

