# Contribution Guide

The contents in this document are available in:

- **English**
- [简体中文](./ContributorGuide.zh-CN.md)

## Code

### Languages in use

In the `master` branch:

- Choose `C++` as the main language for development.
- Choose `Unix Shell` as the language for build scripts. (currently in use but it is possible to be moved in the future)

### Code Styles

For `C++`:

- The [[ISO 14882:2014]](https://www.iso.org/standard/64029.html), also called [ISO C++14], is used for the development excluding the features which are incompatible to the future standards.
  - **NOTE** For example, [[ISO C++14] refresh rules for auto deduction from *braced-init-list*](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html), so some incompatible code shall not be used here.
  - Therefor, the project can be built on [ISO C++14] and later versions.
- The `{` and `}` shall be in one line by itself, except the following cases:
  - As the outermost block of a *lambda-expression*.
  - As the empty *function-body*.
- Except macro names, identifiers of public API shall be in `PascalCase` for classes and `camelCase` for the rest (including denoting the `lambda-expression`).

For `Thesis`:

**TODO** Need practice.

## Document

### Document Localization

The document localization shall conform to the following rules:

- The language code shall be made up of [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) code(in small case), `-` and [ISO 3166-1](https://en.wikipedia.org/wiki/ISO_3166-1) code(in capital case).
- The default language code can be specified by directory name(only allowed under the `doc/` folder). For instance, `doc/zh-CN/` specifies `zh-CN`.
  - If not specified, the default language code is `en-US`.
- The file name of document shall conform to the form `<name>.<language-code>.md`. The language code omits if and only if it is the default language code.
- If there is any of other translated version, the corresponding hyperlink(s) should be appeared in the top of the document.

*Example*: In the root directory, `README.en-US.md => README.md` while the corresponding Chinese version `README.zh-CN.md` shall not omit the language code. Besides, `doc/zh-CN/README.zh-CN.md` shall omit language code and be abbreviated to `doc/zh-CN/README.md`.

## Version

### Version Metadata

The version metadata is maintained in file `version`. In the future, it will be used:

- For Github tag.

And be likely to be used:

- For the `THESIS_INTERPRETER_VERSION` macro of C++, may be synchronized manually or generated automatically by scripts.

### Version Format

The version of the project shall:

- Conformed to the [Semantic Versioning](https://semver.org/).
- Corresponded to the [Project Status](./ProjectStatus.md).
- Updated only by the maintainers.

## Commit

### Commit Messages

**Syntax**:

```bnf
commit-message := <brief>  ["\n" <details>]
brief := [<type> | (<type> "(" <scope> ")") ": "] <text>
details := (<text>)*
```

**Semantics**:

- The `<text>` used above is a sequence of characters ended by `"\n"`.
- The `<type>` is usually one of the followings:
  - `doc`: Add or modify document(s).
  - `fix`: Fix bug(s).
  - **NOTE** One has no need to explicitly specify `<type>` when:
    - The commit only introduces (a) new feature(s).
    - The commit only improves performance (without API modification).
    - The commit contains different types of change, which are unrelated to others (Not recommended).
- The `<scope>` is usually:
  - The name/path of changed file/directory in the commit.
    - Better to put the file name after the directory if any duplicate names. If the complete path is too long, illustrate it in the `<details>`.
  - The position in the project of the added/modified content.

*Example*: `doc(ContributorGuide.md): Revise "Code Styles" chapter.`

### Pull Requests

The pull requests shall be goal-oriented and have a single responsibility.

**NOTE**: That is said, commits of a pull request shall share a small work scope.

The title of a pull request should be:

- Given a type and optional updated scope, whose conventions are similar to [commit messages](#commit-messages).
  - But this time it is helpful to have `feat` type.
  - If refactoring also introduces new features (new API), consider `feat` at first.
  - It is also possible to concatenate two types with `&`. Three or more is not recommended. e.g. `Feat & Refactor`.
- Given a brief of change, which can be rough but necessary.

*Example*: `Refactor: Refactor "std.typechecking" to accept lambda function types.`
