# Brackets

gcc/g++/the c standard (?) has a very peculiar set of valid ranges of identifier
characters.

The parentheses/brackets in "valid:" fields compile with `g++ -Wall -Wextra -std=c++20
what.cpp`. Adding `-Wpedantic` rejects them with an error, clang++ and clangd
reject them outright.

TODO: Find the actual standard (draft) addendum. I'm curious who decides these...

```
uni search -a json parenthesis | jq "map (.char)" | sed "s/\",\?//g" | fmt
[
  ( ) ◌᫁ ◌᫂ ◌᫃ ◌᫄ ⁽ ⁾ ₍ ₎ ⎛ ⎜ ⎝ ⎞ ⎟
  ⎠ ⏜ ⏝ ❨ ❩ ❪ ❫ ⟮ ⟯ ⦅ ⦆ ⸨ ⸩ ⹙ ⹚ ⹛ ⹜
  ﴾ ﴿ ︵ ︶ ﹙ ﹚ （ ） ｟ ｠ 𝅖 𝪋 ␣ ␣
]
invalid: ⎛ ⎞ ⏜ ⏝ ❨ ❩ ❪ ❫ ⟮ ⟯ ⦅ ⦆ ⸨ ⸩ 
valid:   ﴾ ﴿ ︵ ︶ ﹙ ﹚｟ ｠（ ）
```

```
uni search -a json bracket | jq "map (.char)" | sed "s/\",\?//g" | fmt
[
  [ ] { } ◌᫅ ⁅ ⁆ 〈 〉 ⎡ ⎢ ⎣ ⎤ ⎥ ⎦ ⎧ ⎨ ⎩
  ⎪ ⎫ ⎬ ⎭ ⎰ ⎱ ⎴ ⎵ ⎶ ⏞ ⏟ ⏠ ⏡ ❬ ❭ ❰ ❱
  ❲ ❳ ❴ ❵ ⟦ ⟧ ⟨ ⟩ ⟪ ⟫ ⟬ ⟭ ⦃ ⦄ ⦇ ⦈ ⦉
  ⦊ ⦋ ⦌ ⦍ ⦎ ⦏ ⦐ ⦑ ⦒ ⦓ ⦔ ⦕ ⦖ ⦗ ⦘ ⧼ ⧽
  ⸂ ⸃ ⸄ ⸅ ⸉ ⸊ ⸌ ⸍ ⸜ ⸝ ⸢ ⸣ ⸤ ⸥ ⸦ ⸧ ⹕
  ⹖ ⹗ ⹘ 〈 〉 《 》 「 」 『 』 【 】 〔 〕 〖 〗
  〘 〙 〚 〛 ︗ ︘ ︷ ︸ ︹ ︺ ︻ ︼ ︽ ︾ ︿ ﹀ ﹁
  ﹂ ﹃ ﹄ ﹇ ﹈ ﹛ ﹜ ﹝ ﹞ ［ ］ ｛ ｝ ｢ ｣ 𝄕 🄪
  🉀 🉁 🉂 🉃 🉄 🉅 🉆 🉇 🉈 🯌 ␣ ␣ ␣ ␣
]
invalid: ⁅ ⁆ ⟬ ⟭ 【 】⦃ ⦄ 〈 〉❰ ❱ ⧼ ⧽
valid:   ｢ ｣ ｛ ｝︗ ︘
```
