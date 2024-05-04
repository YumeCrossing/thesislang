# 贡献指南

本文档内容的可用语言版本：

- [English](./ContributionGuide.md)
- **简体中文**

## 代码

### 使用中的语言

在主分支（`master`）中：

- 以 `C++` 为主要开发语言。
- 以 `Unix Shell` 为构建脚本的语言。（目前处于使用中，但是可能未来被移除）

### 代码风格

对 `C++`：

- [[ISO 14882:2014]](https://www.iso.org/standard/64029.html)，即 [ISO C++14]，在不使用与未来的标准不兼容的特性的原则下被用于开发。
  - **注释** 例如，[[ISO C++14] 更改了 *braced-init-list* 的自动推导规则](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html)，所以一些使用旧式（[ISO C++11]及以前）写法的代码不应当出现。
  - 因此，项目可以在 [ISO C++14] 及以后版本中构建。
- `{` 和 `}` 应分别占用一行。除非：
  - 作为 *lambda-expression* 的最外层块。
  - 作为空的 *function-body* 块。
- 除去宏的命名，公共 API 的标识符在作为类的名称时应当为 `PascalCase`，其余情况则应当为 `camelCase` （包括指称 *lambda-expression* 时）。

对 `Thesis`：

**TODO** 需要实践。

## 文档

### 文档本地化

文档本地化工作应当符合以下规则：

- 语言代码为（且应当为）[ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) 规定的代码的小写与 `-` 与 [ISO 3166-1](https://en.wikipedia.org/wiki/ISO_3166-1) 规定的代码的大写组成的序列，对应于现实语言。
- 默认语言代码可以被目录名指定（仅在 `doc/` 下可用）。例如，`doc/zh-CN` 指定 `zh-CN`。
  - 若未指定，默认语言代码为 `en-US` 。
- 文档的文件名应当符合 `<名称>.<语言代码>.md` 的形式。当且仅当默认语言代码对应文档语言时，语言代码可被忽略。
- 若文档有翻译版本，文档的顶部应当出现对应的超链接。

*示例*：在根目录下，`README.en-US.md` 被缩略为 `README.md` ，而对应的中文版本 `README.zh-CN.md` 不应当被缩略。此外，`doc/zh-CN/README.zh-CN.md` 应当忽略语言代码并被缩略为 `README.zh-CN.md` 。

## 版本

### 版本元数据

版本元数据在 `version` 文件中维护。
在未来，它将被用于：

- Github 标签。

且可能被用于：

- 项目内的 C++ 宏 `THESIS_INTERPRETER_VERSION` ，可能会被手动同步或由脚本自动生成。

### 版本格式

项目版本信息应当：

- 符合[语义化版本](https://semver.org/lang/zh-CN)规范
- 对应于[项目状态](./ProjectStatus.md)
- 仅被项目维护者更新。

## 提交

### 共识

一律使用英文。

### 提交信息

**语法**：

```bnf
commit-message := <brief>  ["\n" <details>]
brief := [<type> | (<type> "(" <scope> ")") ": "] <text>
details := (<text>)*
```

**语义**：

- `<text>` 为 `\n` 结尾的字符序列。
- `<type>` 通常有以下几种：
  - `doc`：添加或修改文档。
  - `fix`：修复代码中的问题。
  - `refactor`：重构代码。
  - **注释** 当下列情况发生，提交原则上无需指定 `<type>`：
    - 该提交只引入新特性。
    - 该提交只提升性能（而不改变 API）。
    - 该提交同时包含几种类型的更改，且互不关联。（不推荐）
  - 若要指定多种类型，使用 `&` 串接它们。示例：``
- `<scope>` 通常为：
  - 改动的目录/文件的名称。
    - 若有同名文件，最好把所属目录名置前。若过长，则在详情（`<details>`）中说明。
    - 改动内容所属的项目架构中的位置。

*Example*: `doc(ContributorGuide.md): Revise "Code Styles" chapter.`

### 拉取请求

一个拉取请求（以下简称为 PR）应当是目标明确且单一职责的。

**注释**：这就是说，一个 PR 的提交共享一个相同且明确的工作范围。

一个 PR 的标题应当：

- 给出更改的类型和可选的改动范围，约定与上面的[提交信息](#提交信息)相似。
  - 但是在这里，有必要使用 `feat` 标识新功能的引入。
  - 当重构也引入新特性时，优先考虑 `feat` 。
  - 也可以使用 `&` 串联（三个及以上不推荐）。示例：`Feat & Refactor`
- 给出增添或改动内容的概述，可以粗略，但必要。

*Example*: `Feat & Refactor: "std.typechecking" now accepts lambda function types.`
