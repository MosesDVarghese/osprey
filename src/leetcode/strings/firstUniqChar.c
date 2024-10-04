#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
  char ind[26];
  unsigned char occ[26];
  //memset(ind, -1, 26);
  //memset(occ, 0, 26);

  for (int i=0; i<26; i++) {
    occ[i] = 0;
    ind[i] = -1;
  }

  unsigned int size = strlen(s);
  for (short i=0; i<size; i++) {
    char current = s[i];
    //printf("%c", current);

    char index = current - 97;
    //printf("%d \n", index);
    occ[index]++;
    if (ind[index] != -1) {
      ind[index] = i;
    }
    //ind[index] = i; 
  }
  printf("\n");

  unsigned int res = size+1;
  for (int i=0; i<26; i++) {
    if (occ[i] == 1) {
      int index = ind[i];
      if (index != -1 && index < res) {
        res = ind[i];
      }
    }
  }

  return res == size+1 ? -1 : res;  
  //return res;
}

int firstUniqChar2(char* s) {
  unsigned int occ[26];
  int ind[26];
  //memset(occ, 0, 26);
  //memset(ind, -1, 26);

  for (int i=0; i<26; i++) {
    occ[i] = 0;
    ind[i] = -1;
  }
  printf("\n");

  char x = 'k';
  int index = x - 97;
  printf("index: %d \n", index);

  for (int i=0; i<26; i++) {
    char sumn = i + 97;
    printf("%c: %d \n", sumn, occ[i]);
  }
  printf("\n");

  unsigned int size = strlen(s);
  for (short i=0; i<size; i++) {
    char c = s[i];
    //printf("%c", c);

    int index = c - 97;
    occ[index]++;
    //printf("%d \n", index);
  }
  printf("\n");

  //printf("%d \n", occ[0]);


  for (int i=0; i<26; i++) {
    char sumn = i + 97;
    printf("%c: %d \n", sumn, occ[i]);
  }
  printf("\n");


  return 0;  
}

typedef struct {
  int count;
  int index;
} CharInfo;

int firstUniqChar3(char* s) {
  CharInfo char_map[256] = {0};

  for (int i = 0; s[i] != '\0'; ++i) {
    unsigned char c = (unsigned char)s[i];
    if (char_map[c].count == 0) {
      char_map[c].index = i; 
    }
    char_map[c].count++;
  }

  int min_index = -1;
  for (int i = 0; i < 256; ++i) {
    if (char_map[i].count == 1) {
      if (min_index == -1 || char_map[i].index < min_index) {
        min_index = char_map[i].index;
      }
    }
  }

  return min_index;
}

int firstUniqChar4(char* s) {
  unsigned int occ[26] = {0};
  unsigned int ind[26] = {0};

  unsigned int size = strlen(s);
  for (int i=0; i<size; i++) {
    unsigned char c = (unsigned char) s[i] - 97;
    if (occ[c] == 0) {
      ind[c] = i;
    }
    occ[c]++;
  }

  int minIndex = -1;
  for (int i=0; i<26; i++) {
    if (occ[i] == 1) {
      if (minIndex == -1 || ind[i] < minIndex) {
        minIndex = ind[i];
      }
    }
  }
  return minIndex;
}


int main() {
  printf("Hello, World!\n");

  //char s[] = "loveleopards";
  //char s[] = "aaaass";
  char s[] = "jnaprrmwbbujwrgqqtccvkjvxwiimcvmokrdsbgpubcwlveeqeprvoofeepsntdrujehsthrdwunjfedhltnarwsqjxbtuwnnkklsqqmhxthicnwthvenkcvuxhxvpxihelaqariwlxtamqmocwawtcnbmilvswcurgffljwjlhbjknfpkwqckvtfbjwsosetpttjabnjxdcmwtcnievjilfcgtxmdmwmheivjrfvxvnxosrsmiwtvgnwdnwtbtogrwwxuhpetcdmttnvgttxilclxiuhpaodvmnbkwkakncbvwdgwfmitvfamuxapsfsculbtmwqvteqmsvndnctebfvaqkghculsgcjoctdmhaxqasspmermcsbencbaabxdlkxfpcdpxhaaxdnabtclwfwpcrrstxeodjnoechotqkvqoxovnoqvflligxumlttvbccimhqelfxlnotqvwfbkqogjjisxujsjgrehlosbiwpqtoraqihuvkvtaugcirbkrthlmjernseopgqansjutvvtfjxufudllhkaqgtldcupaexegdpbqxvrgxownqameonhaqwxtxetaitmctblfcfwvfdhwghvejhpuwootbxkvkhiarwlcegbrffpcfixtgbqfpthuqknrrbrkpwqqpakrnepxhmrsvktrmudomimlxjhhlkknbtspocopsdlxqtxcnjabnhnksqaxocsltfhcqmmrhmotndmwseqgshsitfgcxfhjebektvrfoqbhfdlxlkdlebsubsiiqerwwngxwlotppejqddepopkdfwoomxrpgjmhbhblwslrqidgsuexnwbpkfgbnknwuokahoiqhofvtmdxjhbtkqcpbpubnbutvqibeuewobrmbidsptstdlenbeqpuewwcinkshfncdhesvsqfahharpptnddjmtjtetsbbeeduhvvsirsoiwcjkwpjleeautxhjlbsxntfcjdpmfhwfbbehkurjuoihdhoitbiawhnggtfielhwrubvcctwbpvocstgdjnfisevfgstghcddmiuqtramowhqrnelsratclnwdjvktfvcijmcudbvmlundeckmsxghjqblpxbodknbvvbqxheivtqrbrcosmdsomwwwplrbldplinnxuqdlgkcthbbbwqtllmlngatrjfrmlwlswlmfmexkgquvuobxmflmupncsdhgxttrplmevmihmhaaafnswpnmccweivtlnwmdgbdwbsmbdwejjfovtdsuoxhqctsdlnqadvioaimqrejrhwvgcijmchiepmxmdjujwotjcexnidhpchsatatnucadrbhilrkuxogbxxgpprvdcjmagjaowxpcpsvpnxceolpfhkboopmniudiluxxxqpdbpppqjuglggvcspdnmtwcaqplrbjodfnpqvctjouwhesqsiuuktnrelveavtvjerbmixantnagalcifutptcncdlxrdvtkcopmipwvjrhktrwggikfmghibimdfxqfpujburftrbeensocscrcoafhefuxrsumudxavvvvsequnaavkrqwiabhnqnfhvhnjmrestgnmcbkedognnpdcpsqetbfabbrvwameeqbburorboxmxhxfuxjinxxefkibbspdxdkprpavukwxwgmrxktkhgckrtsuwagofqhojspxtjevkwinbsojaaptvkhpmtjvunkpfeeqhljoefmsbxkgieowsiojtkarotjkeuhqxqfelfhqxrhqqspmxwqlmulcttfookqwlqiehfdgdifixskmusnfoljxbdoddohtttrjrmweomtfvupxsovgbwljcnmtualgajbbqebdpvcasivvaaioomrawaxdiavabkquuumlxdsjxwfvwcvhmxldtlogagnixwwdgmpluodptghxvtnolorktqcskslhavlvmmkmigvtxqlmdtawtrsofwlpbvxnhaouquewdmhubfqulcwffahhsfrwkvibrnjvsmoqegktllqxshxlqmrmrvmhhlqlqokdreaklogxftrdsmcbfdnocwdjxqfutjclfesniktbfomtcrbxsowmfqxvckaukqiqofmbuubrncjnlekmjntptlicrtisnboqvfnffkxgvrxbtwgacjtxthwrtkxxngklbfgkwgpatkaruxmfdahtgmbbawtlcwfscwhpuxxqjuscwhgjguhlclilijfvcjhvroinjvigwropipseddtabcfxecfvhxidnpjdeajktaunsfkxqptcddwutbteaqanwqjkoaeshbeputljhpwqwemcogpswmocviksovpjkmvdxxidasvdupxturqoxllljbksmhtvejrjslqfbcqtncoevkqbofhpscstqwqgoiocfgsoegxxxxtirrfsikkxitjmdkgwhrvwihipiocpufefjohcpsetmebgumvsafwmeiqxwsimductmkirsgmsnnaqtkmuxkavqqtpnclgventdlpojmunegidbvemprfifxipngbebvmnusdbvgstihxwvwfkvttwcfbggodhphbibafmvswfjindpdxvtwtxpsuejliohsknsdfejsccxsmhqwsvaufkugctndkcsgilfvdmcuvtdtcmxofletixkjtisxxtptltmvgjhcgpufbcmtchxvgpaepgjqqixjlegsqgatoiswxiauxqcjncpvncrenrrjxpuwhjfxvtoafhctnxfpwxvvxxkngpvrimnqecpodkpbcxcptlohrhmvllfstclkpkrixkgqivftapqqlnpiocutsojctjunkcbghjavtlbfvhvwlehumodbmboppvpbbddkgohfvfcociarurptuwtfiuvapgungwkmsckaoliqhssrgunlhqujqwefdtdlpsleuvbgwedsmukpbmundvumcqowdmnsfiikuffxfquejxqbfsrrqufohrqlgksbqxagjnnmkqswvtmijnwpawwxpsuuovakialjnlclguoajoxfwgsabcaxcljbrmjuvlkjwicobdhcndioemfcujkghlasiqepgpuivlhltgvnbqhvtqqpcsuupcxxkiktnvbucnammeqhvovqdssnaowbsbqbbnbriekhnnoxmwjjiebblrdgjnjvqilolxtxavghfmqokuhmdltpfnurtoeijowxrfigmxfomboaxvcgokdchiefachlvelvlppwwtativbfljlrrccbcpdewqlelcchroqiujgwcqqvwkjdmkpgwfjvwjxumhjmdclchahhsbtixfuwgtdqcihapeeeqlcgqsbwhbdwpacwifnrrfnxpievlcqshhmejxjsutttdxoxhalmthfuwwbeitfajlinobdivxgoudwtvgoonkdfvkvnxocnfwnthxppuuvhdhlssawjovqdmlqailiaejlvubgwpthwijdvwgeuardgnrcvluodwdtdmqapxlettbasqhpxjnvhoouvqomndflnbedjmfuhlikkbdqkdkeurangwmlothgtbmjmgjaqbgqgrmogmxkpehfkwejwfajwnbbqughqgcjeihbrmoxwpunhigrftawmesenhvbvxfqogxjuvublegupmtaltauoqaithnhbpwklskphvlkukosasdqawitfhdiduxqknojswiclotrtieqervinuhmhccrdgkucqevvikcwgtxxpxnkcbaiewoojnnuehlijretbqqsgedaxirjwrjshuramvlxiggmqfqubjlgfongqgndkdcuwsohdslcignwfxaihglrvqgjjchhbplupiusftgxvqooiqfxforvmcejemkncwfmsflidrtupttuipnjbsurlvswxddfuphlbsttnuslvaligftgermfkjfilpehqujaswfsdducaggksjugwmrijfhppjueosufhkbnfoptbgnkmucsgteeakhufrtkwtpbovnmcgwvoxxiufuaoveagxfftgcsphseqidputgaqtvvjnkjedsnmfkltranlffwukkgrmjuwxvhfefgbmvrcmvhdjfbiwjpmucrksojsfrhorufvbvnqlghexkhhkfpgoubomgxsfbgvfxqabcjotovnloaqicwlxhextxwhgltjpxgjvnwtdmaamjdsaxelaedlpmgbbjvealwknfsamihtdmphumrgqjptxcapgdweadcrqcpfvdexxgwvrbwdaiohdtsdupftoxbhwndkhtgebxxfjhbmhbchmwndtpspkileavqxjlvcaisxenthwcjlsdcamkuivfahocutmirivqxlstnnnfncelpkxrnqxhikhfbaqmsaxhwassvgtbnftngrltmvpnlduuoemwiipfxaurfjbhjmxjwfrqsrghrdnclirhlrntsjbauaowrxhiwviqfcdvskbmitwfulaqpmbqkrdgvgtbasbewqhipxqenpekbfjvoblqwfhxfiemleedvncxgudbsccolrxqahiqcudkrpsjhlqvtidkqhkupojxlvtldipqvoggjjermhfdgqcsgjelmraxpsegqcrrpkbmvhdtshmuhgqooccbjdagrqlhiggcqsednqwajefqpsnwcktlwojshoqijmveimodsooxbphqfuitjiqduasvlosjnlwnirausxdicndlilkesorqjtupmorqtfsaoajhwemdurrbcbdrxcvshvogrhohdqjkttclpvrbqkqdsesdpnfsmpjuerjvufknqacimklrmhaihfhbkwqpkavaeecdimgitqcpulclcbcalmltqhobxkjlrppaonulflkxrxvqaagdfqwbrgjjvlfutedmwhnhxjbakpvpqmdkvthunfpfduktcrmhqdbdikxcgdkqqekeddhlukiijfiapxcsekxphnogxdtucscsajfxwwvhpwwmagxekkadgmdtupicneudcnswmqoufpvoofagttlauvbsvwksrlqxkwosukkodpmgjwhgfhbgjaosssrewhnoqwqdxsbojxenkhmxjmjdnxstlberehljvlrporvcxhvkxrpwimujqrgnjemqdvdpxoiqxhtufxofkuxnqnrpsvcrckqslxfiihnoumgumpahcqetdhrwlmfopvrwuoavogchuxmbswchguhixuuedoiurlxuwcnfllnvorftanuvajaugkbtslseovbezjduqwfgaetkchmqcxpoqptrljsuvatxpoamppvwwvtdhvlmvtwcmkndsgvnxvnsedtvintfbbjxrmsawugtghrisccgdxdstjcawshkaqhpqtinfshsaowxdokhafmgfjgngnavusdcubhddnqgrxgrdrfpwwrxbjglcwiadhhroavbxfcikspweksooucvxtmljvfiaprlgpdpskfqrhcvwdlfxoppawgeulaiqcjrcoqpsujfbohwptgujmqvdsgprgbofjrdmnghbtfihxgtrjmlmguaqosekxasgciatedphqlivkxjlpvijefqhekshomntgnbqtjqljrgsabtouagpgrmjlqjougxfwjfjcwjfiqjgxnpjahtpejvvtcdrhhhlqevabclvlqksjlvulaahpuceesfibmofwfavrpguebrvetopfmmkfmmfhokbialepwhhqtrikkvxcvcdxlxfpplqspxwwsxxkfsoqqfmumgbcaahpvdkgowvgmphsrrgrmichmbfuaoslvaegcvqqjvflhqctgkbtarmxionbtkkhveifbqpxirxkgsrlbkjqmolwdmllqvbnnjnktsqbdctrkgtrkinqpphwpsicgvanictpaljijxsslmjnbvoliliocadwmsohnfasaenllrdlrlcpvitbqtpfvpuhlfmtlkwftfbcrqogmewxxkmsphufqxdflwjjdsvgqvpfllmctwvvhkjgfovfdpbammnjvvlhangmjkuwxkaknjdwcienoavbgpaujkcpdmxhkoguaagmjobqvwqfibpwartiwcjgjdboqpcdohpmcsdviqcfctiilavowmbmscebjerdraetkvkgrfifewhahugxhrrjfiqqwgteqkehxgnrbouogjevmghbcrrnevwtoewomficsoeihlwgqnigsnxoxdbqvtvdtpurvdokkmasfknojrsfisgeghksjhvwtxuotcijjjqgborhsfsjqffvwwllpmpfptotgcfgfuuwefcpdljbiftaiiuubxcjpldjwugqawvbwibaubgprtivumwtnlwbdqkjchkrqpchhgmifprksovlkdqcvgemtklblvbavodapiojnoccfxqucnshpqdmoahkjlmnruiuvfmkoochiwuhdjvulctqftfvmlbisisdcwadwoijekgmhpqhdunpqlfrdvcjklafosrtgwvartaemilsffadhgafabpapedkbsieoiqvhkrflmxmlgelshndbnhgsebtlgmnfsjooxrqmklftwjxammshukrsdewtfvomeaefjbnotxmwwiplwgskuqkrimmlxthuhgqfbifdgmdtoalbmjljoscvthwjgxjtscagwggjeajufkedpinobxppvxsohikbwegabmsbuwwxduiioiaxvxlxoecjnxtalvalkrxdhllvjaqkslevetunvufeosmximawanxgfrggpwvhsqbamsmqdjkfkdgfobflejqmfxikuufqaxiaveckqctfkcxtumpanmudqfjqbukvbbhuasvbtaxuonjbdonoewsenmscogkgxfhfflpwmcwsnwkwtobmaqchflrosahtsdrulhxrmaaxaneudvcecjuupsafneidrulpkgvrddvsgawbdkaurrikesfpismxfhpgerriibnuajiwunewwaglmckldinhoeudoxtmmmannpslwgmprponwsnlviktkmbetjdgomgngddiaorcjfqbttinxjdtuwikrvjoxaqedevfletoxluwceckquigskafafglpamrtcxbwjlskhtodfdcrqrgnbrfrrixvmevhfknsdxitldpaodvrvwbubtkuijqjnobwoebperwjxfthqckcdhaqnotikhpvcecjewnmexevjsaasqsjdnsqsckopdugdutxiabjrdmptbwevngqegjfkhfviohpbitriteavlnofrxtirtxwddgefvwtxqnthjpwfpoxjgsnmbudvmvknreiubqlfodjqgakqswiuqufbwqohqdhkdhxflufscptfkmcsfoxmdmehmwkqgivujoqorctvebcvfeqnigejxsliuhojpnvjlsmjeruoelnawqehkxqltmjlvckqlcwlasrmebjnjsnwxamsvbbsivgqbqxpkwirbhjjrejsfarhockfxlcoxtshgbuuekudwadglhmvgnjlujfarnixogoavurrqvirxoinbfcwnrvdbtoltjnnfajegbhfxqhdejpfuumfkdofnquwueqbwwurjrmqrcwruiawmejlvllcprpbfjjrxdnqgmtjguxdruehrwsgnsetiopepojokmgrmkbsgfrbrukklsfhlacoiwnxitxbnupnerqkbovlfbkgjpexieevhcicqjlajbxcomhjwhjrmcueuwpusxkwfcbnjagfftfskbhqoxheaijceweiravlkuwrsxhxtluuaiwvbxxkhkirjifkpaelftjekhgvbbrphtorpoxusbjjttrbcgxfhvsqkpmjamonbpxuxfrtjffcjirxdtpdilxlkaxsqndfupipltnwundvnxmtkptuamchbkkibtgxaijibrrutcminxcvprtigjlsjektcprtpncrchpxflofcjefsbxhujawqwbdfadbimeqwmogdjtkumilkbibintkhbgqqpfjcnwxejhinltbkbrxqgnotmdgwnkcemvlgbqfofjhdcubwxmrudxxfpjkfjtkjofhmacrsiusfoqsghlrggucnwuouwtgwwffebvvjejjsggdlqfqwxgqnauskdchfdewnviidxwmutxovdkelxvsdoboqjwguokqrlekhrotjesslqdwpghwahmkoabjmoxeoealpdgpscpppghxatwomumouhdcfeulnamtbfawgewvpoonhpkqxuktsgcxoqidowiswwtbxtauehrkurbwqiuxppicjjdgrovagxprtouvwsxnosfhbpmlmhncmhgdvjsgjhnetwlofgqvwrnkissqbrpoquardhasxhumpdtiqefmfxkrwbumwtaivvrsdxnnhwuxheomiefbjmtdttmbtfhxtnrffkdicvoplcmqgnamshqigbkoxifljcjkbikbimbtsmtopqgnkjkqrcusembmjuarwpisjsncnlvuoequprxlkpexiidsrmpcwkhbvxswegkecsfjtirrkqbmuulgcknfppxilfroxoifcjweefalbmubascwevkksxwwmrscwdroxsrnlrlpgteglpxlgngcxrolawlcimebjerfpdkgtgjdwosnsmcdfgoppcwwpssfqqtkcefrwnlasnmvgivowvhkbvswjeksmojfcmvgqhtvnumbdrhmipqevqpkhlmquncxasjprvqspuclbqrdetbvvtodqwahswowuhjkrwliknxspeknscknhvopgoppmiouocgbpdsfvosnpocibmeemwaxhcqakmjxnmpdfuxtpiloxokgtagslqkuetmdgrhjdfmxrasqbcteilbgohrhgjoenrjgpiqromnpeprwtfjpcwxqlqtudrujktbsmbnxpjtcgloduivxfwmtkmwplbkrtseqolndoffawjirwupurmjbdskkoaswpvqgfxbnsimrweixpbqgvagjvlndealpxvhobmavnjhvubfeqwhvcrbtkhbmfogetrjhblkdnbgmjdpsrmfbqheianfmamkntkeixdxplpbxvqhiscqkpdgoqnscpkpkxqktrfabxejehiugtjcaofhojrpqqqndwsspiamjqafurfwmtqdepmaafoevdmfqkjnumoeiqsfqbmncdicuabansxkrkrojjekkuuounkkoipkatbhssmxdcchmmnrgumbjsuexabtagouxdkcendouthgoqanxkacjugwhjpaetrlnlleujjegnpexpmcnfbgclbcoiukeopalkwdjferlcktxjoiodgmuhwssfgipjascbackknwrjxkhorilnifiavofpakucnkaqewjadkcjwjffsjflhxevnegxajfswohxxbnxxvftrjsiutcfsmjawgnnwejisinomswpqikhorxfnhelkuahrtcjdlqwspmmrceaxkbunbcvnmsuwvhlwufkhwkkvudlwaxrtdkmxcvansmrxbqdeawsroxgmobbvepdflvvllpffbrkuibrexfxckhignihtgugvdsqkehwesthgaetnjcsbtlaesxvlpwsskjveoxbtebaflilqpftphrawuwkcogxnacmiigxjqdeianhvaosmikxdtnxdlsuvggvxsmipvjnaitxlmowpgxmepevuptsd";
  int res = firstUniqChar3(s);

  printf("res: %d \n", res);

  return 0;
}

// notes
// I need a map of all english alphabet, but then again, do I?
// I know it's a char
// if I know it's a char, I can know its ascii value
// it's only lower case, so it's only 26 possible characters right
