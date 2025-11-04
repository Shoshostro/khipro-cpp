// Copyright (c) Jayed Ahsan Saad
//
// This is a C++ port of the khipro-python, which is licensed
// under the MIT License.
//
// Original project: https://github.com/rank-coder/khipro-python
// Copyright (c) 2025 rank_coder
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <algorithm>
#include <iostream>
#include <locale>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> vowels_map = {
    {"o", "অ"}, {"a", "আ"}, {"i", "ই"}, {"ii", "ঈ"},
    {"u", "উ"}, {"uu", "ঊ"}, {"q", "ঋ"}, {"e", "এ"},
    {"oi", "ঐ"}, {"w", "ও"}, {"ou", "ঔ"}, {"ae", "অ্যা"},
    {"wa", "ওয়া"}, {"we", "ওয়ে"}, {"wae", "ওয়্যা"}, {"oo", "ঽ"},
    {"fo", ""}, {"fa", "া"}, {"fi", "ি"}, {"fii", "ী"},
    {"fu", "ু"}, {"fuu", "ূ"}, {"fq", "ৃ"}, {"fe", "ে"},
    {"foi", "ৈ"}, {"fw", "ো"}, {"fou", "ৌ"}, {"fuf", "‌ু"},
    {"fuuf", "‌ূ"}, {"fqf", "‌ৃ"}, {"fae", "্যা"}, {"fwa", "োয়া"},
    {"fwe", "োয়ে"}, {"fwae", "ওয়্যা"}, {"ngo", "ঙ"}, {"nga", "ঙা"},
    {"ngi", "ঙি"}, {"ngii", "ঙী"}, {"ngu", "ঙু"}, {"nguff", "ঙ‌ু"},
    {"nguu", "ঙূ"}, {"nguuff", "ঙ‌ূ"}, {"ngq", "ঙৃ"}, {"ngqff", "ঙ‌ৃ"},
    {"nge", "ঙে"}, {"ngoi", "ঙৈ"}, {"ngw", "ঙো"}, {"ngou", "ঙৌ"},
    {"ngae", "ঙ্যা"}, {"ngof", "ঙঅ"}, {"ngaf", "ঙআ"}, {"ngif", "ঙই"},
    {"ngiif", "ঙঈ"}, {"nguf", "ঙউ"}, {"nguuf", "ঙঊ"}, {"ngqf", "ঙঋ"},
    {"ngef", "ঙএ"}, {"ngoif", "ঙই"}, {"ngwf", "ঙও"}, {"ngouf", "ঙউ"}, {"ngaef", "ঙঅ্যা"}};

unordered_map<string, string> vowel_signs_map = {
    {"o", ""}, {"a", "া"}, {"i", "ি"}, {"ii", "ী"},
    {"u", "ু"}, {"uu", "ূ"}, {"q", "ৃ"}, {"e", "ে"},
    {"oi", "ৈ"}, {"w", "ো"}, {"ou", "ৌ"}, {"ae", "্যা"},
    {"of", "অ"}, {"af", "আ"}, {"if", "ই"}, {"oif", "ই"},
    {"iif", "ঈ"}, {"uf", "উ"}, {"ouf", "উ"}, {"uuf", "ঊ"},
    {"qf", "ঋ"}, {"ef", "এ"}, {"wf", "ও"}, {"aef", "অ্যা"},
    {"uff", "‌ু"}, {"uuff", "‌ূ"}, {"qff", "‌ৃ"}, {"we", "োয়ে"},
    {"wef", "ওয়ে"}, {"waf", "ওয়া"}, {"wa", "োয়া"}, {"wae", "ওয়্যা"}};

unordered_map<string, string> consonants_map = {
    {"k", "ক"}, {"kh", "খ"}, {"g", "গ"}, {"gh", "ঘ"},
    {"ngf", "ঙ"}, {"c", "চ"}, {"ch", "ছ"}, {"j", "জ"},
    {"jh", "ঝ"}, {"nff", "ঞ"}, {"tf", "ট"}, {"tff", "ঠ"},
    {"tfh", "ঠ"}, {"df", "ড"}, {"dff", "ঢ"}, {"dfh", "ঢ"},
    {"nf", "ণ"}, {"t", "ত"}, {"th", "থ"}, {"d", "দ"},
    {"dh", "ধ"}, {"n", "ন"}, {"p", "প"}, {"ph", "ফ"},
    {"b", "ব"}, {"v", "ভ"}, {"m", "ম"}, {"l", "ল"},
    {"sh", "শ"}, {"sf", "ষ"}, {"s", "স"}, {"h", "হ"},
    {"y", "য়"}, {"rf", "ড়"}, {"rff", "ঢ়"}, {",,", "়"}};
unordered_map<string, string> conjuncts_map = {
    {"rz", "র‍্য"},
    {"kk", "ক্ক"},
    {"ktf", "ক্ট"},
    {"ktfr", "ক্ট্র"},
    {"kt", "ক্ত"},
    {"ktr", "ক্ত্র"},
    {"kb", "ক্ব"},
    {"km", "ক্ম"},
    {"kz", "ক্য"},
    {"kr", "ক্র"},
    {"kl", "ক্ল"},
    {"kf", "ক্ষ"},
    {"ksf", "ক্ষ"},
    {"kkh", "ক্ষ"},
    {"kfnf", "ক্ষ্ণ"},
    {"kfn", "ক্ষ্ণ"},
    {"ksfnf", "ক্ষ্ণ"},
    {"ksfn", "ক্ষ্ণ"},
    {"kkhn", "ক্ষ্ণ"},
    {"kkhnf", "ক্ষ্ণ"},
    {"kfb", "ক্ষ্ব"},
    {"ksfb", "ক্ষ্ব"},
    {"kkhb", "ক্ষ্ব"},
    {"kfm", "ক্ষ্ম"},
    {"kkhm", "ক্ষ্ম"},
    {"ksfm", "ক্ষ্ম"},
    {"kfz", "ক্ষ্য"},
    {"ksfz", "ক্ষ্য"},
    {"kkhz", "ক্ষ্য"},
    {"ks", "ক্স"},
    {"khz", "খ্য"},
    {"khr", "খ্র"},
    {"ggg", "গ্গ"},
    {"gnf", "গ্‌ণ"},
    {"gdh", "গ্ধ"},
    {"gdhz", "গ্ধ্য"},
    {"gdhr", "গ্ধ্র"},
    {"gn", "গ্ন"},
    {"gnz", "গ্ন্য"},
    {"gb", "গ্ব"},
    {"gm", "গ্ম"},
    {"gz", "গ্য"},
    {"gr", "গ্র"},
    {"grz", "গ্র্য"},
    {"gl", "গ্ল"},
    {"ghn", "ঘ্ন"},
    {"ghr", "ঘ্র"},
    {"ngk", "ঙ্ক"},
    {"ngkt", "ঙ্‌ক্ত"},
    {"ngkz", "ঙ্ক্য"},
    {"ngkr", "ঙ্ক্র"},
    {"ngkf", "ঙ্ক্ষ"},
    {"ngkkh", "ঙ্ক্ষ"},
    {"ngksf", "ঙ্ক্ষ"},
    {"ngkh", "ঙ্খ"},
    {"ngg", "ঙ্গ"},
    {"nggz", "ঙ্গ্য"},
    {"nggh", "ঙ্ঘ"},
    {"ngghz", "ঙ্ঘ্য"},
    {"ngghr", "ঙ্ঘ্র"},
    {"ngm", "ঙ্ম"},
    {"ngfk", "ঙ্ক"},
    {"ngfkt", "ঙ্‌ক্ত"},
    {"ngfkz", "ঙ্ক্য"},
    {"ngfkr", "ঙ্ক্র"},
    {"ngfkf", "ঙ্ক্ষ"},
    {"ngfkkh", "ঙ্ক্ষ"},
    {"ngfksf", "ঙ্ক্ষ"},
    {"ngfkh", "ঙ্খ"},
    {"ngfg", "ঙ্গ"},
    {"ngfgz", "ঙ্গ্য"},
    {"ngfgh", "ঙ্ঘ"},
    {"ngfghz", "ঙ্ঘ্য"},
    {"ngfghr", "ঙ্ঘ্র"},
    {"ngfm", "ঙ্ম"},
    {"cc", "চ্চ"},
    {"cch", "চ্ছ"},
    {"cchb", "চ্ছ্ব"},
    {"cchr", "চ্ছ্র"},
    {"cnff", "চ্ঞ"},
    {"cb", "চ্ব"},
    {"cz", "চ্য"},
    {"jj", "জ্জ"},
    {"jjb", "জ্জ্ব"},
    {"jjh", "জ্ঝ"},
    {"jnff", "জ্ঞ"},
    {"gg", "জ্ঞ"},
    {"jb", "জ্ব"},
    {"jz", "জ্য"},
    {"jr", "জ্র"},
    {"nc", "ঞ্চ"},
    {"nffc", "ঞ্চ"},
    {"nj", "ঞ্জ"},
    {"nffj", "ঞ্জ"},
    {"njh", "ঞ্ঝ"},
    {"nffjh", "ঞ্ঝ"},
    {"nch", "ঞ্ছ"},
    {"nffch", "ঞ্ছ"},
    {"ttf", "ট্ট"},
    {"tftf", "ট্ট"},
    {"tfb", "ট্ব"},
    {"tfm", "ট্ম"},
    {"tfz", "ট্য"},
    {"tfr", "ট্র"},
    {"ddf", "ড্ড"},
    {"dfdf", "ড্ড"},
    {"dfb", "ড্ব"},
    {"dfz", "ড্য"},
    {"dfr", "ড্র"},
    {"rfg", "ড়্‌গ"},
    {"dffz", "ঢ্য"},
    {"dfhz", "ঢ্য"},
    {"dffr", "ঢ্র"},
    {"dfhr", "ঢ্র"},
    {"nftf", "ণ্ট"},
    {"nftff", "ণ্ঠ"},
    {"nftfh", "ণ্ঠ"},
    {"nftffz", "ণ্ঠ্য"},
    {"nftfhz", "ণ্ঠ্য"},
    {"nfdf", "ণ্ড"},
    {"nfdfz", "ণ্ড্য"},
    {"nfdfr", "ণ্ড্র"},
    {"nfdff", "ণ্ঢ"},
    {"nfdfh", "ণ্ঢ"},
    {"nfnf", "ণ্ণ"},
    {"nfn", "ণ্ণ"},
    {"nfb", "ণ্ব"},
    {"nfm", "ণ্ম"},
    {"nfz", "ণ্য"},
    {"tt", "ত্ত"},
    {"ttb", "ত্ত্ব"},
    {"ttz", "ত্ত্য"},
    {"tth", "ত্থ"},
    {"tn", "ত্ন"},
    {"tb", "ত্ব"},
    {"tm", "ত্ম"},
    {"tmz", "ত্ম্য"},
    {"tz", "ত্য"},
    {"tr", "ত্র"},
    {"trz", "ত্র্য"},
    {"thb", "থ্ব"},
    {"thz", "থ্য"},
    {"thr", "থ্র"},
    {"dg", "দ্‌গ"},
    {"dgh", "দ্‌ঘ"},
    {"dd", "দ্দ"},
    {"ddb", "দ্দ্ব"},
    {"ddh", "দ্ধ"},
    {"db", "দ্ব"},
    {"dv", "দ্ভ"},
    {"dvr", "দ্ভ্র"},
    {"dm", "দ্ম"},
    {"dz", "দ্য"},
    {"dr", "দ্র"},
    {"drz", "দ্র্য"},
    {"dhn", "ধ্ন"},
    {"dhb", "ধ্ব"},
    {"dhm", "ধ্ম"},
    {"dhz", "ধ্য"},
    {"dhr", "ধ্র"},
    {"ntf", "ন্ট"},
    {"ntfr", "ন্ট্র"},
    {"ntff", "ন্ঠ"},
    {"ntfh", "ন্ঠ"},
    {"ndf", "ন্ড"},
    {"ndfr", "ন্ড্র"},
    {"nt", "ন্ত"},
    {"ntb", "ন্ত্ব"},
    {"ntr", "ন্ত্র"},
    {"ntrz", "ন্ত্র্য"},
    {"nth", "ন্থ"},
    {"nthr", "ন্থ্র"},
    {"nd", "ন্দ"},
    {"ndb", "ন্দ্ব"},
    {"ndz", "ন্দ্য"},
    {"ndr", "ন্দ্র"},
    {"ndh", "ন্ধ"},
    {"ndhz", "ন্ধ্য"},
    {"ndhr", "ন্ধ্র"},
    {"nn", "ন্ন"},
    {"nb", "ন্ব"},
    {"nm", "ন্ম"},
    {"nz", "ন্য"},
    {"ns", "ন্স"},
    {"ptf", "প্ট"},
    {"pt", "প্ত"},
    {"pn", "প্ন"},
    {"pp", "প্প"},
    {"pz", "প্য"},
    {"pr", "প্র"},
    {"pl", "প্ল"},
    {"ps", "প্স"},
    {"phr", "ফ্র"},
    {"phl", "ফ্ল"},
    {"bj", "ব্জ"},
    {"bd", "ব্দ"},
    {"bdh", "ব্ধ"},
    {"bb", "ব্ব"},
    {"bz", "ব্য"},
    {"br", "ব্র"},
    {"bl", "ব্ল"},
    {"vb", "ভ্ব"},
    {"vz", "ভ্য"},
    {"vr", "ভ্র"},
    {"vl", "ভ্ল"},
    {"mn", "ম্ন"},
    {"mp", "ম্প"},
    {"mpr", "ম্প্র"},
    {"mph", "ম্ফ"},
    {"mb", "ম্ব"},
    {"mbr", "ম্ব্র"},
    {"mv", "ম্ভ"},
    {"mvr", "ম্ভ্র"},
    {"mm", "ম্ম"},
    {"mz", "ম্য"},
    {"mr", "ম্র"},
    {"ml", "ম্ল"},
    {"zz", "য্য"},
    {"lk", "ল্ক"},
    {"lkz", "ল্ক্য"},
    {"lg", "ল্গ"},
    {"ltf", "ল্ট"},
    {"ldf", "ল্ড"},
    {"lp", "ল্প"},
    {"lph", "ল্ফ"},
    {"lb", "ল্ব"},
    {"lv", "ল্‌ভ"},
    {"lm", "ল্ম"},
    {"lz", "ল্য"},
    {"ll", "ল্ল"},
    {"shc", "শ্চ"},
    {"shch", "শ্ছ"},
    {"shn", "শ্ন"},
    {"shb", "শ্ব"},
    {"shm", "শ্ম"},
    {"shz", "শ্য"},
    {"shr", "শ্র"},
    {"shl", "শ্ল"},
    {"sfk", "ষ্ক"},
    {"sfkr", "ষ্ক্র"},
    {"sftf", "ষ্ট"},
    {"sftfz", "ষ্ট্য"},
    {"sftfr", "ষ্ট্র"},
    {"sftff", "ষ্ঠ"},
    {"sftfh", "ষ্ঠ"},
    {"sftffz", "ষ্ঠ্য"},
    {"sftfhz", "ষ্ঠ্য"},
    {"sfnf", "ষ্ণ"},
    {"sfn", "ষ্ণ"},
    {"sfp", "ষ্প"},
    {"sfpr", "ষ্প্র"},
    {"sfph", "ষ্ফ"},
    {"sfb", "ষ্ব"},
    {"sfm", "ষ্ম"},
    {"sfz", "ষ্য"},
    {"sk", "স্ক"},
    {"skr", "স্ক্র"},
    {"skh", "স্খ"},
    {"stf", "স্ট"},
    {"stfr", "স্ট্র"},
    {"st", "স্ত"},
    {"stb", "স্ত্ব"},
    {"stz", "স্ত্য"},
    {"str", "স্ত্র"},
    {"sth", "স্থ"},
    {"sthz", "স্থ্য"},
    {"sn", "স্ন"},
    {"sp", "স্প"},
    {"spr", "স্প্র"},
    {"spl", "স্প্ল"},
    {"sph", "স্ফ"},
    {"sb", "স্ব"},
    {"sm", "স্ম"},
    {"sz", "স্য"},
    {"sr", "স্র"},
    {"sl", "স্ল"},
    {"hn", "হ্ন"},
    {"hnf", "হ্ণ"},
    {"hb", "হ্ব"},
    {"hm", "হ্ম"},
    {"hz", "হ্য"},
    {"hr", "হ্র"},
    {"hl", "হ্ল"},
    {"ksh", "কশ"},
    {"nsh", "নশ"},
    {"psh", "পশ"},
    {"ld", "লদ"},
    {"gd", "গদ"},
    {"ngkk", "ঙ্কক"},
    {"ngks", "ঙ্কস"},
    {"ngfkk", "ঙ্কক"},
    {"ngfks", "ঙ্কস"},
    {"cn", "চন"},
    {"cnf", "চণ"},
    {"jn", "জন"},
    {"jnf", "জণ"},
    {"tft", "টত"},
    {"dfd", "ডদ"},
    {"nft", "ণত"},
    {"nfd", "ণদ"},
    {"lt", "লত"},
    {"sft", "ষত"},
    {"nfth", "ণথ"},
    {"nfdh", "ণধ"},
    {"sfth", "ষথ"},
    {"ktff", "কঠ"},
    {"ktfh", "কঠ"},
    {"ptff", "পঠ"},
    {"ptfh", "পঠ"},
    {"ltff", "লঠ"},
    {"ltfh", "লঠ"},
    {"stff", "সঠ"},
    {"stfh", "সঠ"},
    {"dfdff", "ডঢ"},
    {"dfdfh", "ডঢ"},
    {"ndff", "নঢ"},
    {"ndfh", "নঢ"},
    {"ktfrf", "ক্টড়"},
    {"ktfrff", "ক্টঢ়"},
    {"kth", "কথ"},
    {"ktrf", "ক্তড়"},
    {"ktrff", "ক্তঢ়"},
    {"krf", "কড়"},
    {"krff", "কঢ়"},
    {"khrf", "খড়"},
    {"khrff", "খঢ়"},
    {"gggh", "জ্ঞঘ"},
    {"gdff", "গঢ"},
    {"gdfh", "গঢ"},
    {"gdhrf", "গ্ধড়"},
    {"gdhrff", "গ্ধঢ়"},
    {"grf", "গড়"},
    {"grff", "গঢ়"},
    {"ghrf", "ঘড়"},
    {"ghrff", "ঘঢ়"},
    {"ngkth", "ঙ্কথ"},
    {"ngkrf", "ঙ্কড়"},
    {"ngkrff", "ঙ্কঢ়"},
    {"ngghrf", "ঙ্ঘড়"},
    {"ngghrff", "ঙ্ঘঢ়"},
    {"ngfkth", "ঙ্কথ"},
    {"ngfkrf", "ঙ্কড়"},
    {"ngfkrff", "ঙ্কঢ়"},
    {"ngfghrf", "ঙ্ঘড়"},
    {"ngfghrff", "ঙ্ঘঢ়"},
    {"cchrf", "চ্ছড়"},
    {"cchrff", "চ্ছঢ়"},
    {"tfrf", "টড়"},
    {"tfrff", "টঢ়"},
    {"dfrf", "ডড়"},
    {"dfrff", "ডঢ়"},
    {"rfgh", "ড়ঘ"},
    {"dffrf", "ঢড়"},
    {"dfhrf", "ঢড়"},
    {"dffrff", "ঢঢ়"},
    {"dfhrff", "ঢঢ়"},
    {"nfdfrf", "ণ্ডড়"},
    {"nfdfrff", "ণ্ডঢ়"},
    {"trf", "তড়"},
    {"trff", "তঢ়"},
    {"thrf", "থড়"},
    {"thrff", "থঢ়"},
    {"dvrf", "দ্ভড়"},
    {"dvrff", "দ্ভঢ়"},
    {"drf", "দড়"},
    {"drff", "দঢ়"},
    {"dhrf", "ধড়"},
    {"dhrff", "ধঢ়"},
    {"ntfrf", "ন্টড়"},
    {"ntfrff", "ন্টঢ়"},
    {"ndfrf", "ন্ডড়"},
    {"ndfrff", "ন্ডঢ়"},
    {"ntrf", "ন্তড়"},
    {"ntrff", "ন্তঢ়"},
    {"nthrf", "ন্থড়"},
    {"nthrff", "ন্থঢ়"},
    {"ndrf", "ন্দড়"},
    {"ndrff", "ন্দঢ়"},
    {"ndhrf", "ন্ধড়"},
    {"ndhrff", "ন্ধঢ়"},
    {"pth", "পথ"},
    {"pph", "পফ"},
    {"prf", "পড়"},
    {"prff", "পঢ়"},
    {"phrf", "ফড়"},
    {"phrff", "ফঢ়"},
    {"bjh", "বঝ"},
    {"brf", "বড়"},
    {"brff", "বঢ়"},
    {"vrf", "ভড়"},
    {"vrff", "ভঢ়"},
    {"mprf", "ম্পড়"},
    {"mprff", "ম্পঢ়"},
    {"mbrf", "ম্বড়"},
    {"mbrff", "ম্বঢ়"},
    {"mvrf", "ম্ভড়"},
    {"mvrff", "ম্ভঢ়"},
    {"mrf", "মড়"},
    {"mrff", "মঢ়"},
    {"lkh", "লখ"},
    {"lgh", "লঘ"},
    {"shrf", "শড়"},
    {"shrff", "শঢ়"},
    {"sfkh", "ষখ"},
    {"sfkrf", "ষ্কড়"},
    {"sfkrff", "ষ্কঢ়"},
    {"sftfrf", "ষ্টড়"},
    {"sftfrff", "ষ্টঢ়"},
    {"sfprf", "ষ্পড়"},
    {"sfprff", "ষ্পঢ়"},
    {"skrf", "স্কড়"},
    {"skrff", "স্কঢ়"},
    {"stfrf", "স্টড়"},
    {"stfrff", "স্টঢ়"},
    {"strf", "স্তড়"},
    {"strff", "স্তঢ়"},
    {"sprf", "স্পড়"},
    {"sprff", "স্পঢ়"},
    {"srf", "সড়"},
    {"srff", "সঢ়"},
    {"hrf", "হড়"},
    {"hrff", "হঢ়"},
    {"ldh", "লধ"},
    {"ngksh", "ঙ্কশ"},
    {"ngfksh", "ঙ্কশ"},
    {"tfth", "টথ"},
    {"dfdh", "ডধ"},
    {"lth", "লথ"},
    {"kkf", "কক্ষ"},
    {"lkf", "লক্ষ"},
    {"sfkf", "ষক্ষ"},
    {"skf", "সক্ষ"},
    {"kkkh", "কক্ষ"},
    {"lkkh", "লক্ষ"},
    {"sfkkh", "ষক্ষ"},
    {"skkh", "সক্ষ"},
    {"kksf", "কক্ষ"},
    {"lksf", "লক্ষ"},
    {"sfksf", "ষক্ষ"},
    {"sksf", "সক্ষ"},
    {"yr", "য়র"}};

unordered_map<string, string> reph_map = {{"rr", "র্"},
                                          {"rae", "র‍্যা"}};

unordered_map<string, string> phola_map = {{"z", "য"}, {"r", "র"}};

unordered_map<string, string> diacritics_map = {
    {"qq", "্"}, {"xx", "্‌"}, {"t/", "ৎ"}, {"x", "ঃ"},
    {"ng", "ং"}, {"/", "ঁ"}, {"//", "/"}, {"`", "`"},
    {"``", "‌"}, {"```", "``"}, {"~", "~"}, {"~~", "‍"}, {"~~~", "~~"}};

unordered_map<string, string> punctuations_map = {
    {";", ""}, {";;", ";"}, {".", "।"}, {"...", "..."},
    {"..", "."}, {"$", "৳"}, {"$f", "₹"}, {"$$", "$"},
    {",,,", ",,"}, {".f", "॥"}, {".ff", "৺"}, {"+", "+"},
    {"-", "-"}, {"=", "="}, {"+f", "×"}, {"-f", "÷"}, {"=f", "≠"}};

unordered_map<string, string> digits_map = {
    {".1", ".১"}, {".2", ".২"}, {".3", ".৩"}, {".4", ".৪"}, {".5", ".৫"},
    {".6", ".৬"}, {".7", ".৭"}, {".8", ".৮"}, {".9", ".৯"}, {".0", ".০"},
    {"1", "১"}, {"2", "২"}, {"3", "৩"}, {"4", "৪"}, {"5", "৫"},
    {"6", "৬"}, {"7", "৭"}, {"8", "৮"}, {"9", "৯"}, {"0", "০"},
    {"A", "a"}, {"B", "b"}, {"C", "c"}, {"D", "d"}, {"E", "e"},
    {"F", "f"}, {"G", "g"}, {"H", "h"}, {"I", "i"}, {"J", "j"},
    {"K", "k"}, {"L", "l"}, {"M", "m"}, {"N", "n"}, {"O", "o"},
    {"P", "p"}, {"Q", "q"}, {"R", "r"}, {"S", "s"}, {"T", "t"},
    {"U", "u"}, {"V", "v"}, {"W", "w"}, {"X", "x"}, {"Y", "y"}, {"Z", "z"}};

set<string> global_keys_set;
int max_token_length = 0;

void initialize_global_keys()
{
  auto populate_globals = [&](const auto &map_to_add)
  {
    for (const auto &pair : map_to_add)
    {
      global_keys_set.insert(pair.first);
      if (pair.first.length() > max_token_length)
      {
        max_token_length = pair.first.length();
      }
    }
  };

  populate_globals(vowels_map);
  populate_globals(vowel_signs_map);
  populate_globals(consonants_map);
  populate_globals(conjuncts_map);
  populate_globals(diacritics_map);
  populate_globals(punctuations_map);
  populate_globals(phola_map);
  populate_globals(reph_map);
  populate_globals(digits_map);

  if (global_keys_set.empty())
  {
    max_token_length = 0;
  }
}

vector<string> tokenize(const string &text)
{
  vector<string> tokens;
  if (text.empty() || max_token_length == 0)
  {
    if (!text.empty())
    {
      for (char c : text)
      {
        tokens.push_back(string(1, c));
      }
    }
    return tokens;
  }

  size_t i = 0;
  while (i < text.length())
  {
    bool matched = false;
    for (int l = max_token_length; l > 0; --l)
    {
      if (i + l <= text.length())
      {
        string segment = text.substr(i, l);
        if (global_keys_set.count(segment))
        {
          tokens.push_back(segment);
          i += l;
          matched = true;
          break;
        }
      }
    }
    if (!matched)
    {
      tokens.push_back(text.substr(i, 1));
      i += 1;
    }
  }
  return tokens;
}

string transliterate(const string &input)
{
  string output_str;
  vector<string> tokens = tokenize(input);
  bool previous_was_consonant = false;

  for (const string &token : tokens)
  {
    if (conjuncts_map.count(token))
    {
      output_str += conjuncts_map.at(token);
      previous_was_consonant = true;
    }
    else if (consonants_map.count(token))
    {
      output_str += consonants_map.at(token);
      previous_was_consonant = true;
    }
    else if (diacritics_map.count(token))
    {
      output_str += diacritics_map.at(token);
      previous_was_consonant = false;
    }
    else if (reph_map.count(token))
    {
      output_str += reph_map.at(token);
      previous_was_consonant = false;
    }
    else if (punctuations_map.count(token))
    {
      output_str += punctuations_map.at(token);
      previous_was_consonant = false;
    }
    else if (phola_map.count(token))
    {
      if (previous_was_consonant)
      {
        output_str += "্";
        output_str += phola_map.at(token);
      }
      else
      {
        output_str += phola_map.at(token);
      }
      previous_was_consonant = true;
    }
    else if (vowels_map.count(token))
    {
      if (previous_was_consonant)
      {
        if (vowel_signs_map.count(token))
        {
          output_str += vowel_signs_map.at(token);
        }
        else
        {
          output_str += vowels_map.at(token);
        }
      }
      else
      {
        output_str += vowels_map.at(token);
      }
      previous_was_consonant = false;
    }
    else if (vowel_signs_map.count(token))
    {
      output_str += vowel_signs_map.at(token);
      previous_was_consonant = false;
    }
    else if (digits_map.count(token))
    {
      output_str += digits_map.at(token);
      previous_was_consonant = false;
    }
    else
    {
      output_str += token;
      previous_was_consonant = false;
    }
  }
  return output_str;
}

int main()
{
  initialize_global_keys();

  cout << "khipro cpp" << endl;
  cout << "type 'exit' to quit." << endl;

  string sample_input;
  while (true)
  {
    cout << "Enter input: ";
    getline(cin, sample_input);

    if (sample_input == "exit")
    {
      break;
    }

    string result = transliterate(sample_input);
    cout << "Output: " << result << endl;
  }

  return 0;
}
