/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }
        int diff = 0;
        for (int c: cnt) {
            if (c != 0) {
                ++diff;
            }
        }
        if (diff == 0) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            int x = s2[i] - 'a', y = s2[i - n] - 'a';
            if (x == y) {
                continue;
            }
            if (cnt[x] == 0) {
                ++diff;
            }
            ++cnt[x];
            if (cnt[x] == 0) {
                --diff;
            }
            if (cnt[y] == 0) {
                ++diff;
            }
            --cnt[y];
            if (cnt[y] == 0) {
                --diff;
            }
            if (diff == 0) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    // bool ret = sol.checkInclusion("ab", "eidbaooo");
    bool ret = sol.checkInclusion("flxvrcznjvpetwlglbxwjudtqpzqvlnezneorrzorbvcmewanlepafgsrrrnpbephanazfbxrffjpyyfgebnrnezpgbdzgpnpueusqmazuimfswqkcckovejskabxenbcaazsvloswwkeodbqwhvxuvolckoqbbnmylzdykqwihipfbuwqdjtsnprhvbvskjuqwpavovgtwldzlndpwmtapvuwbshlnzftqvikeugeesftjjfqxqckzcmckerqvkfgmutzfspubcmqdxgibkcctysaacjftxofhsyfvzubtlespxdphkcoexblqsywiaewxrypjltlyuktgcisryrodgwvmvnhmhkxvlxwkeuicjolldhvzjbugqbrprkkrptqpvolwbugjviwtewtfcojmeomitugthftnerwxidotaagigjegcqnvnntqaqzhutvwvyhslwxecgnpkbvqcooqyhwfkzigvwvixvthypyxwkwmxljljewnnsjopbgjfeumiafqbnhuusnwuogqobcaurezmvlsekvoxhmlwjvssrtqqhhcoscumxztetoxorhwyypymamovyeupopsxleapzyrwpuovvscxgghurnyabzpgrhjxsfaijsrcgnxafozqzkxzuprajukehkveqoopkbacynmabxkqawbvrtwbycmscktmhrtqzovvuaiaufnjkedpuwmasoxfcupizsiahnqofrqtwiluabwqwgyoeyrvkckqhozzxwqljwdrfcvhgmxgnasznkbxtvsjcunfzlpotxxsnfzuwjzrbvlazfvfobiukbcwqtjspztcsyscfasoauiofidyghfcsprdfzoavbtogicxnqliknlmiktdznjlmzczdtcinkiownvghvtdqfuigzfsumxbczwornoryzaxxvhiwngkconhdullpvkknjaioxwirycxwzxhhvujyliatmygomyisezkekotaxhhgviyonctjcqxxratadwfubdglijbgfvyloeeorwgrzxlhrexoffiamvdvzuujscreombfwukuudpgahcixvbczupnhawfdzfuiuefbnhevggxejbmbqgwxdcjfoxpmstyignzleofrojkxdotjzbgzyacguvmpgbfiemcmgswfzheosyjykvjsxmegdqtsedqxwhizdrtxqfxngqiiqhdqnkucnvlajdqsxthauceyfdxykklduhpfmswacvfcsyoubdrkqvhgmmrgjccdzoojrncgvapuejthnhkouupbvkvynfupbswyybwwiowdrsbpgfdqjyyjhkchhfllhpvnalptuxbpamxowxsragkazpftugfbxsrpzheymxdzisjguptpqsarhcfmhitdijcsdjtbjvciltewuxzckxnomjxzyimkpngwnryirysnihsorufktzhudantlkwpkgvgyannrgjhesrlefdwmkduhlypuivofvpdlzsrateylguvjrgmmpijxrlmcdqljkosrpjslxhpnvpaokqjkzxewjqxuerjyiitblgxpyfkufzuxwaxjougwiycsrwkyydzodmovuweeirbvuhvagqyjuvxchixdeplbmqepstpigawwljxepceapijvbqovlpwykrpmrqfacnfhbwlmisiuvwyijosxkuogtqpnfmqzoynsgfobzzasrwyazkirlsiiysjwysiqedfocdzzyhodvmhxkwroqxqjwfdlgmxlosbcqsgwnrdzjzwlechqalhqucneolyiypgvbnksjmhgildwbirijufnmsncdsakvswmwhzyelfndxxuvpgaeeibtchnxtbqqwqlrnaudohtiqzwlukrhjyhwvzmletyvndyikrpihpablsriolffyfjnopvdookfaccshcanohnjpafoxeszlhzgkwsdbuhrcqysmgwivobhlpiluzqrubblfvjxprjetvaanjxsloekhomfuysdyuyqorcmcjahvcjqkgmubbsfjfvgskbwkoubiremtdoxxztwvzikfumvdewiybnhsdvqaxvicfcokukryovhcynkqzydteyekflfbclzenbucqtzsgnmpemlfxaihaceoeewykkyepswtoxscqneytxctegnhlmvzvpryjmzvwcnoixiszxksjvhktroafqbwvfegjyvolzwqlmbfeoisqjirnprchgtujddwkvvneznqzmsghpokfhziuegdpieqlpfqalfxqbzrpdoqbujwrplehdacigxnieatlhftvgfqssvunkpoqnntybqaankwywnfgnzfkqayzaunlbqvhrzijpxsjyjmuiqhtfmazkvsqzitrwbawfxbsoqiqdtxzciypqurzdoqhhcnokzbuyvuldwkjcbrlcxagrtfjxxqkmisqzsimvnssmuhxwscqtlqplhlalhntclgakvbvtcrrzzesxcrurpqkrrmffwdinnlebzfradplhapmybwfdfdohhonajvyzgosfqrmfjoujmubrnocohzudbjniswmfqolsyigwteuifmasbubrzrjijhkcdxqgqixeoddrhtpmemigpormizdizhdxnazfiqqrywjselyzekpjtpucrtopokqbupebdvcjzazfeyyyhkuagfsmyrnmkewkaxaznwcdzusfajvamlobazycdjcnqxpgwkokvqejkkaumbksrotynsmwddfmykqkwfzxaspoapvbunvmmtllrzmldohpkrkoyotsycrtbtplxxsuvzrkqgqalelevsrdxtbzfpueasccuabjrhxeopzjgyoouzydyvzxnqqefjrwldltfjgtjafwumxsthgvzqcjjtotdbrokenyrfsjiofsxmlkkkmdsjwvqejdnvewslkkhuclfbvucwxwwgobszgmkewcscaupxisowechkjfylkeffpsaenxkhcogiyqmsgpvtdlowfssmolidndirzkcobmcjcyqymhqdgnckakkyjuzpdwgvfwoitfavpycfoocwewxyvgshfpydbhhgkauprdexcnfvxxqymzugwhbxfidemmbeznjneqmeuzrxkyvbyetangjfetehnlzhybsaigwljsktxdcqkpkbvwnlcwrpofcxxethfspabgrmihcgpmsamptaydawwznlcvmqgdalcwxkdnphxrhgkrjtlfbdxtotjrgimshvzljnvjbywuylhwfadtvqkjjevvvbrumdsbcnexsjzlzzmydghsrxerlttsoujuzhdixkrutvzevnealyzfzgzjdzvapyrsuwyplsvufcpbrtadhoyncxdpcfrzcgukjnuvqhrnhzaimsmaekhmutymgvyjikaaibnmvbmgolfuwmopcpiusimdzsqkmeneqbesjlkrsfieypkkztttiqfcnquiknsgurcoertbeehxgwquvkzvwdapsxznannzkqtukcfwafzyxedjnbdrvbtjkqufovtnbmhrxbofqzljltfkinklrsuyckmufosfoncfpvkoqketlcbkvkoxobbncnoiwedzfgvyqtfwlozewaystejiloauopqctjeitjwyqbxdhtogvqmsvplxvmodtcbpmwyqjcspjwxqatwpsjhngsuanvqjtntnuqplajsevmyqschmgwxfcdkynf", "yaalpjvqjqqczxgxfyinagfcuvkgoqzeezcgymzlinnibplbkwifxzjazrbaabqstpncuoeuricouwpyqltwwkkojtyqarkuwpmlxchvuwamjzvsqwnzhkneopswdtmvysjumpilfopzeiccnkxjpvdhhqiygpcrnmsarpanfrbdhxpmhuoujxtfyskijevauvojuzzaxxmhtwrtvcjzccwclytwojsbkvbekjdbpmjehgrwyttjakluwhbexeewjfiyjcoqtjehrstjetyyubuhauoqkwojgekglomfrwgknjwbovlnbjqxpgvaqlmhpnuiixtwcxmmwgflkhsclpsgysvuygqswbwblrmvsmyumeylcxufqgrbgrzqelzrsxslomyimfrrvjwkuaezjisnddsqsnonunlqctjlaosplbiyhaptmsjhfeswczhioyclfryrnkkujlrocpzfuiedxvzmmvttixqmaninfadgbogflcukuontwcfpwjargnhyelrlkuziojhfaoyplbtojadvndxihvdhhinjtqetxcgseheunstynawujjipowdnucjzgujzwrwjgiycafkkwzemwpzjxfecefynvoyekfdkgdddyryhlxgtlozjcwyrkokxdlsdsemamcspzriuzlqujsogmgwikksvakmadzwjijhlqsawtrskrqfwunqxzscjiewtibmctcxezflxvrcznjvpetwlglbxwjudtqpzqvlnezneorrzorbvcmewanlepafgsrrrnpbephanazfbxrffjpyyfgebnrnezpgbdzgpnpueusqmazuimfswqkcckovejskabxenbcaazsvloswwkeodbqwhvxuvolckoqbbnmylzdykqwihipfbuwqdjtsnprhvbvskjuqwpavovgtwldzlndpwmtapvuwbshlnzftqvikeugeesftjjfqxqckzcmckerqvkfgmutzfspubcmqdxgibkcctysaacjftzofhsyfvzubtlespxdpukcoexblqsywiaewxrypjltlyuktgcisryrodgwvmvnhmhkxvlxwmeuicjolldhvzjbugqbrprkkrptqpvolwbugjviwtewtfcojmeomitugthftnerwxidotaagigjegcqnvnntqaqzhttvwvyhslwxecgnpkbvqcooqyhwfkzigvwvyxvthypyxwkwmxojljewnnsjopbgjfeumiafqbnhuusnwuogqobcaurezmvlsekvoxhmlwjvssrtqqhhcoscumxztetoxorhwyypymamovyehpopsxleapzyrwpuovvscxgghurnyabzpgrhjxsfaijsqcgnxafozqzkxzuprajukehkveqoopkbacynmabxkqawbvrtwbycmscktmhrtqzovvuaiaufnjkedpuwmasoxfcupizsiahnqofrqtwiluabwqwgyoeyrvkckqhozzxwqljwdrfcvhgmxgnasznkbxtvsjcunfzlpotxxsnfzuwjzrbvlazfvfobiukbcwqtjspztcsyscfasoauiofidyghfcsprdfzoavbtogicxnqliknlmiktdznjlmzczdtcinkiownvghvtdqfuigzfsumxbczwornoryzaxxvhiwngkconhdullpvkknjaioxwirycxwzxhhvrjyliatmygomyisezkekotaxhhgviyonctjcqxxratadwfubdglijbgfvyloeeorwgrzxlhrexoffiamvdvzuujscreombfwukuudpgahcixvbczupnhawfdzfuiuefbnhevggxejbmbqgwxdcjfoxpmstyignzleofrojkxdotjzbgzyacguvmpgbfiemcmgswfzheosyjykvjsxmegdqtsedqxwhixdrtxqfxngqiiqhdqnkucnvlajdqsxthauceyfdxykklduhpfmswacvfcsyoubdrkqvhgmmrgjccdzoojrncgvapuejthnhkouupbvkvynfupbswyybwwiowdrsbpgfdqjyyjhkchhfllhpvnalptuxbpamxowxsragkazpftugfbxsrpzheymxdzisjguptpqsarhcfmhitdijcsdjtbjvciltewuxzckxnomjxzyimkpngwnryirysnihsooufktzhudantlkwpkgvgyannrgjhesrlefdwmkduhlywuivofvpdlzsrateylguvjrgmmpijxrlmcdqljklsrpjslxhpnvpaokqjkzxewjqouerjyiitblqxpyfkufzuxwaxjougwiycsrwkyydzodmovuweeirbvuhvagqyjuvxchixdeplbmqepstpigawwljxepceapijvbqovlpwykrpmrqfacnfhbwlmisiuvwyijosxkuogtqpnfmqzoynsgfobzzasrwyazkirlsiiysjwysiqedfocdzzyhodvmhxkwroqxqjwfdlgmxlosbcqsgwnrdzjzwlechgalhqdcneolyiypgvbnksjmhgildwbirijufnmsncdsakvswmwhzyelfndxxuvpgaeeibtchnxtbqqwqlrnaudohtiqzwlukrhjyhwvzmletyvndyikrpihpablsriolffyfjnopvdookfaccshcanohnjpafoxeszlhzgkwsdbuhrcqysmgwivobhlpiluzqrubblfvjxprjetvaanjxsloekhomfuysdyuyqorcmcjahvcjqkgmubbsfjfvgskbwkoubiremtdoxxztwvzikfumvdewiybnhsdvqaxvicfcokukryovhcynkqzydteyekflfbclzenbucqtzsgnmpemlfxaihaceoeewykkyepswtoxscqneytxctegnhlmvzvpuyjmzvwcnoixiszxksjvhktroafqbwvfegjyvolzwqlmbfeoisqjirnprchgtujddwkvvneznqzmsghpokfhziuegdpieqlpfqalfxqbzrpdoqbujwrplehdacigxnieaulhftvgfqssvunkpoqnntybqaankwywnfgnzfkqayzaunlbqvhrzijpxsjyjmuiqhtfmazkvsqzitrpbawfxbsoqiqdtxzciyqqurzdoqhhcnokzbuyvuldwkjcbrlcxagrtfjxxqkmisqzsimvnsskuhxwscqtlqplhlalhntclgakvbvtcrrzzesxcrurpqkrrmffwdinnlebzfradplhapmybwfdfdohhxnajvyzgosfqrmfjoujmubrnocohzudbjniswmfrolsyigwteuifmasbubrzrjijhkcdxqgqixeoddrhtpmemigpormizdizhdxnazfiqqriwjselyzekpjtpucrtopokqbupebdvcjzazfeyyyhkuagfsmyrnmkewkaxaznwcdzusfajvamlobazycdjcnqxpgwkokvqejkkaumbksrotynsmwddfmykqkwfzxaspoapvbunvmmtllrzmldohpkrkoyotsycrtbtplxxsuvzrkqgqalelevsrdxtbzfpueasccuabjrhxeopzjgyoruzydyvzxnqqefjrwldltfjgtjafwumxsthgvzqcjjtotdbrokenyrfsjiofsxmlkkkmdsjwvqejdnvewslkkhuclfbvucwxwwgobszgmkewcscaupxisowechkjfylkeffpsaenxkhcogiyqmsgpvtdlowfssmolidndirzkcobmcjcyqymhqugnckakkyjuzpdwgvfwoitfavpycfoocwewxyvgshfpydbhhgkauprdexcnfvxxqymzugwhbxfidemmbeznjneqmeuzrxkyvbyetangjfetehnlzhybsaigwldsktxdcqkpkbvwnlcwrpofcxxethfspabgrmihcgpmsamptaydawwznlcvmqgdalcwxkdnphxrhgkrjtlfbdxtotjrgimshvzljnvjbywuylhwfadtvqkjjevvvbrumdsbcnexsjzlzzmydghsrxerlttsoujuzhdixkrutvzevnealyzfzgzjdzvapyrsuwyplsvufcpbrtajhoyncxdpcfrzcgukjnuvqhrnhzaimsmaekhmutymgvyjikaaibnmvbmgolfuwmopcpiusimdzsqkmeneqbesjlkrsfieypkkztttiqfcnquiknsgurcoertbeehxgwquvkzvwdapsxznannzkqtukcfwafzyxedjnbdrvbtjkqufovtnbmhrxbofqzljltfkinklrsuyckmufosfoncfpvkoqketlcbkvkoxobbncnoiwedzfgvyqtfwlozewaystejiloauopqctjeitjwyqbxdhtogvqmsvplxvmodtcbpmwyqjcspjwxqatwpsjhngsuanvqjtntnuqplajsevmypschmgwxfcdkynfzlhsqqwdcgdbxpezgdkpjcoqtaddqfsahlphsqxofdfevbncnjawmmgth");
    return 0;
}

/* 滑动窗口，比较两个值的
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};

*/

/* 解不出来，用排序超时
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        int head = 0;
        int size = s1.size();
        if ((head + size) > s2.size())
        {
            return false;
        }

        sort(s1.begin(), s1.end());
        while (true)
        {
            string temp = s2.substr(head, size);
            sort(temp.begin(), temp.end());
            if (temp == s1)
            {
                return true;
            }
            else
            {
                head++;
                if ((head + size) > s2.size())
                {
                    return false;
                }
            }
        }
        return false;
    }
};
*/