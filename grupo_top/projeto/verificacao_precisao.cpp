#include <iostream>
#include <string>

void PrintNum(std::string s, int n)
{
  for(int i = 0; i < n; i++)
    std::cout<< s[i];
}

void comp(std::string a, std::string b ) 
{
  int maior = a.length()>b.length()?a.length():b.length(); 

  for(int i = 3;i < maior;i++) 
    if(a[i]!=b[i])
    {
      std::cout <<"Diferença na posição "<< i-1 << "; precisão de " << i-2 <<" casas";
      std::cout << "\nnumero com casas até a certa: ";
      PrintNum(a,i);
      return;
    }
}

int main() {
std::string resultado = ""; //colocar resultado dos programas aqui
std::string referencia = "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637721112523897844250569536967707854499699679468644549059879316368892300987931277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684161403970198376793206832823764648042953118023287825098194558153017567173613320698112509961818815930416903515988885193458072738667385894228792284998920868058257492796104841984443634632449684875602336248270419786232090021609902353043699418491463140934317381436405462531520961836908887070167683964243781405927145635490613031072085103837505101157477041718986106873969655212671546889570350354021234078498193343210681701210056278802351930332247450158539047304199577770935036604169973297250886876966403555707162268447162560798826517871341951246652010305921236677194325278675398558944896970964097545918569563802363701621120477427228364896134225164450781824423529486363721417402388934412479635743702637552944483379980161254922785092577825620926226483262779333865664816277251640191059004916449982893150566047258027786318641551956532442586982946959308019152987211725563475463964479101459040905862984967912874068705048958586717479854667757573205681288459205413340539220001137863009455606881667400169842055804033637953764520304024322566135278369511778838638744396625322498506549958862342818997077332761717839280349465014345588970719425863987727547109629537415211151368350627526023264847287039207643100595841166120545297030236472549296669381151373227536450988890313602057248176585118063036442812314965507047510254465011727211555194866850800368532281831521960037356252794495158284188294787610852639813955990067376482922443752871846245780361929819713991475644882626039033814418232625150974827987779964373089970388867782271383605772978824125611907176639465070633045279546618550966661856647097113444740160704626215680717481877844371436988218559670959102596862002353718588748569652200050311734392073211390803293634479727355955277349071783793421637012050054513263835440001863239914907054797780566978533580489669062951194324730995876552368128590413832411607226029983305353708761389396391779574540161372236187893652605381558415871869255386061647798340254351284396129460352913325942794904337299085731580290958631382683291477116396337092400316894586360606458459251269946557248391865642097526850823075442545993769170419777800853627309417101634349076964237222943523661255725088147792231519747780605696725380171807763603462459278778465850656050780844211529697521890874019660906651803516501792504619501366585436632712549639908549144200014574760819302212066024330096412704894390397177195180699086998606636583232278709376502260149291011517177635944602023249300280401867723910288097866605651183260043688508817157238669842242201024950551881694803221002515426494639812873677658927688163598312477886520141174110913601164995076629077943646005851941998560162647907615321038727557126992518275687989302761761146162549356495903798045838182323368612016243736569846703785853305275833337939907521660692380533698879565137285593883499894707416181550125397064648171946708348197214488898790676503795903669672494992545279033729636162658976039498576741397359441023744329709355477982629614591442936451428617158587339746791897571211956187385783644758448423555581050025611492391518893099463428413936080383091662818811503715284967059741625628236092168075150177725387402564253470879089137291722828611515915683725241630772254406337875931059826760944203261924285317018781772960235413060672136046000389661093647095141417185777014180606443636815464440053316087783143174440811949422975599314011888683314832802706553833004693290115744147563139997221703804617092894579096271662260740718749975359212756084414737823303270330168237193648002173285734935947564334129943024850235732214597843282641421684878721673367010615094243456984401873312810107945127223737886126058165668053714396127888732527373890392890506865324138062796025930387727697783792868409325365880733988457218746021005311483351323850047827169376218004904795597959290591655470505777514308175112698985188408718564026035305583737832422924185625644255022672155980274012617971928047139600689163828665277009752767069777036439260224372841840883251848770472638440379530166905465937461619323840363893131364327137688841026811219891275223056256756254701725086349765367288605966752740868627407912856576996313789753034660616669804218267724560530660773899624218340859882071864682623215080288286359746839654358856685503773131296587975810501214916207656769950659715344763470320853215603674828608378656803073062657633469774295634643716709397193060876963495328846833613038829431040800296873869117066666146800015121143442256023874474325250769387077775193299942137277211258843608715834835626961661980572526612206797540621062080649882918454395301529982092503005498257043390553570168653120526495614857249257386206917403695213533732531666345466588597286659451136441370331393672118569553952108458407244323835586063106806964924851232632699514603596037297253198368423363904632136710116192821711150282801604488058802382031981493096369596735832742024988245684941273860566491352526706046234450549227581151709314921879592718001940968866986837037302200475314338181092708030017205935530520700706072233999463990571311";
  comp(resultado, referencia);
}
