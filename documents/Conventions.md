# Naming conventions

### Classes

> ***PascalCase***

Class

MyClass

---

### Functions

#### Names

> ***camelCase***, single word capitalised

Function

myFunction

#### Parameters

> camelCase

Function(int parameter)

myFunction(int myParameter)

---

### Variables

> ***camelCase***

variable

myVariable

#### Variable modifiers

##### Stack variables

> snake_case

int variable

int my_variable

##### Pointers

> PascalCase

int* Variable

MyClass* MyVariable

##### Public

> ***Nothing***

##### Protected

> ***Nothing***

##### Private

> ***m_*** before variable

m_variable

m_myVariable

##### Static

> ***s_*** before variable

s_variable

s_myVariable

##### *In case of variables being static and private*

> ***m_s_*** before variable

m_s_variable

m_s_myVariable

---

### Comments

> ***flatcase***, variables keep their case, no full stops

#### General comments

*Contain the default rule set*

```cpp
// this is a comment without variables
// this is a comment referencing the m_s_privateStaticVariable variable
```

#### Variable comments

*Contain the default rule set but must use @brief, @param, @return etc. and start with triple slashes. Must note the param and return their respective type and name*

```cpp
/// @brief explanation of variable
/// @param MyClass* variableParam: explanation of param
/// @return m_myVariable: explanation of return 
```

---

### Defines

> ***SCREAMING_SNAKE_CASE***

VARIABLE

MY_VARIABLE
