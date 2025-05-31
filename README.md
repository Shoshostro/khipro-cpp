# Khipro

Khipro is a Bengali keyboard layout that aims to provide the fastest typing experience for Bengali using lowercase-only input. 

This repository contains the C++ port of this layout.


# Documentation

## Introduction

When writing in the phonetic layout of the Avro keyboard, we need to press Shift repeatedly, disrupting the writing flow and continuity. Therefore, the writing speed cannot increase beyond a certain limit. In China's 'Pinyin' Romanization system, case-insensitive phonetic mapping is used. Thus, we are trying to bring similar speed to Bengali Romanization-based typing. Using Pinyin-based input methods, the Chinese are writing their complex language faster than English. The development of the Khipro keyboard is still ongoing. If you have any complaints or suggestions, you can contact us at the link [below](#Contact).



### Mapping Table of Khipro


#### Vowel Letters & Vowel Signs

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| o | (অ কার) | ; | separator and/or conjuct preventor | f{কার} | prevents auto vowel forming |
| {কার}ff | modern style vowel signs | {ব্যঞ্জন}oif | {ব্যঞ্জন} ই | {ব্যঞ্জন}ouf | {ব্যঞ্জন} উ |
| {ব্যঞ্জন}{কার}f | {ব্যঞ্জন}{স্বরবর্ণ} (except ঐ, ঔ) |  |  |  |  |

#### Vowel Signs

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| a | া | i | ি | ii | ী |
| u | ু | uu | ূ | w | ৃ |
| e | ে | oi | ৈ | oo | ো |
| ou | ৌ | ae | ্যা | aef | অ্যা |

#### Consonant Letters

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| k | ক | kh | খ | g | গ |
| gh | ঘ | ng | ঙ | c | চ |
| ch | ছ | j | জ | jh | ঝ |
| nff | ঞ | tf | ট | tff | ঠ |
| df | ড | dff | ঢ | nf | ণ |
| t | ত | th | থ | d | দ |
| dh | ধ | n | ন | p | প |
| ph | ফ | b | ব | bh, v | ভ |
| m | ম | z | য | r | র |
| l | ল | sh | শ | sf | ষ |
| s | স | h | হ | y | য় |
| rf | ড় | rff | ঢ় |  |  |

#### Diacritics and Misc.

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| tq | ৎ | x | ঃ | q | ং |
| / | ঁ | . | । | .. | . |
| ... | ... | ;; | ; | // | / |
| .{সংখ্যা} | .{সংখ্যা} | $ | ৳ |  |  |

#### Some Conjunct Shortcuts

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| ry | র‌্য | ttf | ট্ট | ddf | ড্ড |
| kkh, ksf | ক্ষ | gg, jnff | জ্ঞ | ggg | গ্গ |
| sfk | ষ্ক | sftf | ষ্ট | sftff | ষ্ঠ |
| sfn, sfnf | ষ্ণ | sfp | ষ্প | sfph | ষ্ফ |
| nc | ঞ্চ | nch | ঞ্ছ | nj | ঞ্জ |
| njh | ঞ্ঝ | qq | ◌্ হসন্ত | xx | ◌্{zwnj} |
| ` | [zwnj] | `` | [zwj] |  |  |

#### Examples

| Input | Output | Input | Output | Input | Output |
|--------|--------|--------|--------|--------|--------|
| k;b;r | কবর | kobor | কবর | som aj | সম আজ |
| som faj | সম াজ | somaj | সমাজ | hwdoy | হৃদয় |
| hwffdoy | হ‌ৃদয় | aekauntf | অ্যাকাউন্ট | boi | বৈ |
| boif, bif, b;i, bo;i | বই | bzonjon | ব্যঞ্জন | kkhoma, ksfoma | ক্ষমা |
| twsfna | তৃষ্ণা | biggan, bijnffan | বিজ্ঞান | onogggol | অনগ্গল |
| katqq, katxx | কাত্ | ryam | র‌্যাম | rik;sha, riksha | রিকশা |
| addfa, adfdfa | আড্ডা | doirghz | দৈর্ঘ্য | udxxdiin | উদ‌্দীন |
| udgiironf | উদ‌্গীরণ | brahmonf | ব্রাহ্মণ | kkhrortz | ক্ষ্রর্ত্য |




### Vowels and Kar-diacritics
1. The kars can be written as shown in the table. For example: ka => কা, kae => ক্যা, maepiq => ম্যাপিং, kii => কী, kw => কৃ, koo => কো.
2. Note that 'ae' maps to অ্যা and is placed with vowels. It can be written like this: hae => হ্যা. For just the "ya" sound, press z: hza => হ্যা. The ae mapping helps at the start of words: aekauntf => অ্যাকাউন্ট, aesidf => অ্যাসিড, maepiq => ম্যাপিং.
3. Traditional and modern styles of diacritics: Some consonants use old-style diacritics (ু, ূ, ৃ) ![ছবি](https://github.com/rank-coder/ibus-khipro/assets/54497225/c5fd0724-b2c1-4058-a2ce-b9c59c7c4908). To create modern styles, add ff to the diacritic. Example: ru => রু, ruff => র‌ু ![ছবি](https://github.com/rank-coder/ibus-khipro/assets/54497225/37a339cc-e651-4723-82a1-ff7115078a0b).
4. At the start of a word, diacritic mappings convert to vowels automatically. To prevent this, start the vowel with f: ami => আমি, fami => ামি.
5. To use a vowel instead of a diacritic after a consonant, example: pinifn = পিনইন, kurafn = কুরআন, hoofya = হওয়া; oi & ou works a bit specially: zotoif = যতই, boif = বই, nou = নৌ, bouf = বউ। However you can use the separator: হওয়া <== h;ooya, পিনইন <== pin;in, কুরআন <== kur;an, বই <== b;i.

### Consonants and Conjuncts
1. Writing two consecutive consonants (if they form a conjunct) automatically places a halant between them. Example: ব্যঞ্জন => bzonjon. To prevent this, use the separator: k;b;r => কবর, or use o: kobor => কবর.
3. To force a halant at the end of a consonant, use qq or xx: কাট্ => katfxx.
4. To show a halant without forming a conjunct in the middle of a word, use \` to insert a ZWNJ (zero width non-joiner). Note that there is a shortcut "xx" to show halant without forming conjunct with the next consonant: জসীম উদ্‌দীন <== josiim udxxdiin
5. ্যা is listed and considered as a vowel sign in Khipro for convenience: hae => হ্যা. For just the য phola you can press z: hza => হ্যা.
6. If you try to write র‌্য normally it results in র্য, so use ry for র‍্য: ryam = র‍্যাম, ryapidf = র‍্যাপিড.
8. For quicker input of ড্ড and ট্ট, use ddf and ttf respectively.
9. Some conjuncts are quite popular. For example: জ্ঞ. To type it quickly, use gg: বিজ্ঞান <== biggan. There are special mappings for some other conjuncts as well (see mapping table).



## Contact
* Bangla Input Method Project Group: https://t.me/+oXLVpYDtyDNmYzll
* Discord: https://discord.gg/GPt6s8cb48
* Bangla Localization Community Group: https://t.me/BanglaLocalizationCommunity
* Linux Bangla Group: https://t.me/linux_bangla
