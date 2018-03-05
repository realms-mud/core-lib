//******************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include <mtypes.h>

mapping emoteTemplates = ([
    "ack":"##InitiatorName## ##Adverb## ##Infinitive::ack####TargetPreposition::at####TargetName##.",
    "admire" : "##InitiatorName## ##Adverb## ##Infinitive::admire####TargetName::the ambiguity of admiring without a target##.",
    "agree" : "##InitiatorName## ##Adverb## ##Infinitive::agree####TargetPreposition::with####TargetName##.",
    "agrin" : "##InitiatorName## ##Adverb## ##Infinitive::grin####TargetPreposition::at####TargetName## like an ass.",
    "aha" : "##InitiatorName## ##Adverb## ##Infinitive::go## 'Aha!'##TargetPreposition::at####TargetName##.",
    "ahh" : "##InitiatorName## ##Adverb## ##Infinitive::go## AHHH##TargetPreposition::at####TargetName##.",
    "amorous" : "##InitiatorName## ##Adverb## ##Infinitive::feel## amorous##TargetPreposition::toward####TargetName##.",
    "annoy" : "##InitiatorName## ##Infinitive::be## ##Adverb## annoying##TargetName##.",
    "apologize" : "##InitiatorName## ##Adverb## ##Infinitive::apologize####TargetPreposition::to####TargetName##.",
    "applaud" : "##InitiatorName## ##Adverb## ##Infinitive::give## a round of applause##TargetPreposition::to####TargetName##.",
    "ayt" : "##InitiatorName## ##Adverb## ##Infinitive::wave## ##InitiatorPossessive## hand back and forth##TargetPreposition::in front of####TargetName## and ##Infinitive::say##, 'Are you there?'",
    "backhand" : "##InitiatorName## ##Adverb## ##Infinitive::backhand####TargetName::an invisible, deceased llama##.",
    "baha" : "##InitiatorName## ##Adverb## ##Infinitive::go## BAHAHAHA##TargetPreposition::at####TargetName##.",
    "bark" : "##InitiatorName## ##Adverb## ##Infinitive::bark## like a dog##TargetPreposition::at####TargetName##.",
    "breakdance" : "##InitiatorName## ##Adverb## ##Infinitive::breakdance## like a madman##TargetPreposition::around####TargetName##.",
    "beam" : "##InitiatorName## ##Adverb## ##Infinitive::beam## like a lightbulb.",
    "beep" : "##InitiatorName## ##Adverb## ##Infinitive::beep####TargetName::like a person mercilessly spared from the ravages of sanity.####TargetPreposition::on the nose.##",
    "beg" : "##InitiatorName## ##Adverb## ##Infinitive::beg## like a dog##TargetPreposition::at####TargetName##.",
    "bleed" : "##InitiatorName## ##Adverb## ##Infinitive::bleed##.",
    "blink" : "##InitiatorName## ##Adverb## ##Infinitive::blink####TargetPreposition::at####TargetName##.",
    "blush" : "##InitiatorName## ##Adverb## ##Infinitive::blush####TargetPreposition::while looking at####TargetName##.",
    "boggle" : "##InitiatorName## ##Adverb## ##Infinitive::boggle####TargetPreposition::at####TargetName::at the concept##.",
    "boo" : "##InitiatorName## ##Adverb## ##Infinitive::snarl####TargetPreposition::behind####TargetName::BOO! HISS####TargetPreposition::scaring the $%!@ out of####TargetObjective##!",
    "boot" : "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::an imaginary mime## a boot to the head!",
    "bootie" : "##InitiatorName## ##Adverb## ##Infinitive::shake## ##InitiatorPossessive## bootie!",
    "bop" : "##InitiatorName## ##Adverb## ##Infinitive::bop####TargetName::an invisible flying turtle##!",
    "bored" : "##InitiatorName## ##Infinitive::be## ##Adverb## bored##TargetPreposition::with####TargetName##.",
    "bounce" : "##InitiatorName## ##Adverb## ##Infinitive::bounce## up and down.",
    "bow" : "##InitiatorName## ##Infinitive::bow####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
    "bpoke" : "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an imaginary sea otter## and ##Infinitive::sneer##, 'Does this bug you?'",
    "brb" : "##InitiatorName## ##Adverb## will be right back (after a word from ##InitiatorPossessive## sponsors).",
    "breathe" : "##InitiatorName## ##Infinitive::breathe## ##Adverb::deeply##.",
    "bsigh" : "##InitiatorName## ##Infinitive::sigh## ##Adverb::indignantly## ##TargetPreposition::at####TargetName## and ##Infinitive::mutter##, `I'm bitter!'",
    "bullshit" : "##InitiatorName## ##Adverb## ##Infinitive::think## that is bullshit!",
    "burp" : "##InitiatorName## ##Infinitive::burp## ##Adverb::rudely##.",
    "cackle" : "##InitiatorName## ##Infinitive::throw## ##InitiatorPossessive## head back and ##Infinitive::cackle####TargetPreposition::at####TargetName## ##Adverb::with glee##!",
    "caress" : "##InitiatorName## ##Adverb::gently## ##Infinitive::run## ##InitiatorPossessive## finger down ##TargetPossessive::Name::an invisible, deaf mime's## cheek.",
    "cheer": "##InitiatorName## ##Infinitive::cheer## ##Adverb::enthusiastically####TargetPreposition::at####TargetName##.",
    "cherry": "##InitiatorName## ##Adverb## ##Infinitive::gobble## up a bowl of cherries.",
    "chew": "##InitiatorName## ##Adverb## ##Infinitive::chew## on something.",
    "chirp": "##InitiatorName## ##Infinitive::chirp## ##Adverb::merrily####TargetPreposition::at####TargetName##.",
    "choke": "##InitiatorName## ##Adverb## ##Infinitive::choke####TargetName##.",
    "chortle": "##InitiatorName## ##Infinitive::chortle## ##Adverb::gleefully####TargetPreposition::at####TargetName##.",
    "chuckle": "##InitiatorName## ##Infinitive::chuckle## ##Adverb::politely####TargetPreposition::at####TargetName##.",
    "clap": "##InitiatorName## ##Infinitive::clap## ##Adverb::briefly####TargetPreposition::to####TargetName##.",
    "comfort": "##InitiatorName## ##Adverb## ##Infinitive::comfort####TargetName::a small rock##.",
    "congratulate": "##InitiatorName## ##Adverb## ##Infinitive::congratulate####TargetName::self## on a job well done.",
    "cough": "##InitiatorName## ##Infinitive::cough## ##Adverb::noisily####TargetPreposition::at####TargetName##.",
    "cower": "##InitiatorName## ##Adverb## ##Infinitive::cower####TargetPreposition::from####TargetName::in a corner##.",
    "crack": "##InitiatorName## ##Adverb## ##Infinitive::crack## ##InitiatorPossessive## knuckles.",
    "cringe": "##InitiatorName## ##Infinitive::cringe## ##Adverb::in terror####TargetPreposition::from####TargetName##.",
    "cross": "##InitiatorName## ##Adverb## ##Infinitive::cross## ##InitiatorPossessive## fingers.",
    "cry": "##InitiatorName## ##Adverb## ##Infinitive::burst## into tears.",
    "cuddle": "##InitiatorName## ##Infinitive::cuddle####TargetName::self## ##Adverb::tenderly##.",
    "curtsey": "##InitiatorName## ##Infinitive::curtsey####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
    "dammit": "##InitiatorName## ##Adverb## ##Infinitive::say##, `DAMMIT!'##TargetPreposition::to####TargetName##.",
    "dance": "##InitiatorName## ##Adverb## ##Infinitive::dance####TargetPreposition::with####TargetName::happily####TargetPreposition::, sweeping ####TargetObjective####TargetPreposition::across the dance floor##.",
    "daydream": "##InitiatorName## ##Adverb## ##Infinitive::get## lost in a daydream##TargetPreposition::about####TargetName##.",
    "die": "##InitiatorName## ##Infinitive::roll## over ##Adverb## and ##Infinitive::do## ##InitiatorPossessive## best to look dead.",
    "disagree": "##InitiatorName## ##Adverb## ##Infinitive::disagree####TargetPreposition::with####TargetName##.",
    "doh": "##InitiatorName## ##Adverb## ##Infinitive::smack## ##InitiatorPossessive## head and ##Infinitive::go##, `Doh!'",
    "drool": "##InitiatorName## ##Adverb## ##Infinitive::drool## all over##TargetName::self##.",
    "duck": "##InitiatorName## ##Adverb## ##Infinitive::duck## out of the way.",
    "duh": "##InitiatorName## ##Adverb## ##Infinitive::scream## `DUH!'##TargetPreposition::at####TargetName##.",
    "eek": "##InitiatorName## ##Adverb## ##Infinitive::go## 'eeeeeeeeeeeeek!'##TargetPreposition::to####TargetName##.",
    "eep": "##InitiatorName## ##Adverb## ##Infinitive::go## 'EEEEP!'##TargetPreposition::to####TargetName##.",
    "egrin": "##InitiatorName## ##Infinitive::grin## ##Adverb::evilly####TargetPreposition::at####TargetName##.",
    "eh": "##InitiatorName## ##Adverb## ##Infinitive::say##, `EH?'",
    "embarrass": "##InitiatorName## ##Infinitive::be## ##Adverb::really## embarrassed!",
    "embrace": "##InitiatorName## ##Adverb## ##Infinitive::gather####TargetName::self## in a warm, loving embrace.",
    "explode": "##InitiatorName## ##Adverb## ##Infinitive::explode####TargetPreposition::at####TargetName::all over the room##!",
    "faint": "##InitiatorName## ##Adverb## ##Infinitive::faint##... THUMP!",
    "fart": "##InitiatorName## ##Adverb## ##Infinitive::let## off a real rip-roarer##TargetPreposition::at####TargetName##.",
    "fear": "##InitiatorName## ##Infinitive::shiver## ##Adverb## with fear##TargetPreposition::from####TargetName##.",
    "flash": "##InitiatorName## ##Adverb## ##Infinitive::strip## ##InitiatorPossessive## clothes and ##Infinitive::bare## ##InitiatorPossessive## body for all to see!",
    "flex": "##InitiatorName## ##Adverb## ##Infinitive::flex## ##InitiatorPossessive## muscles##TargetPreposition::at####TargetName##!",
    "flip": "##InitiatorName## ##Adverb## ##Infinitive::flip## head over heels.",
    "flipoff": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## the finger!",
    "flirt": "##InitiatorName## ##Adverb## ##Infinitive::flirt####TargetPreposition::with####TargetName::with disaster##.",
    "flog": "##InitiatorName## ##Adverb## ##Infinitive::flog####TargetName::an invisible, mute mime##!",
    "flop": "##InitiatorName## ##Adverb## ##Infinitive::flop## to the floor... FLOP!",
    "fly": "##InitiatorName## ##Infinitive::put## out ##InitiatorPossessive## arms ##Adverb## and ##Infinitive::run## around like a flying bird.",
    "fondle": "##InitiatorName## ##Adverb## ##Infinitive::fondle####TargetName::self##.",
    "freeze": "##InitiatorName## ##Infinitive::freeze## ##Adverb## and ##Infinitive::turn## into a popsicle!",
    "french": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::an invisible toad## a deep, hot, passionate kiss...it seems to last forever.",
    "frown": "##InitiatorName## ##Adverb## ##Infinitive::frown####TargetPreposition::at####TargetName##.",
    "fume": "##InitiatorName## ##Adverb## ##Infinitive::fume####TargetPreposition::at####TargetName##.",
    "gag": "##InitiatorName## ##Adverb## ##Infinitive::gag####TargetPreposition::at####TargetName##.",
    "gasp": "##InitiatorName## ##Infinitive::gasp## ##Adverb::in astonishment####TargetPreposition::at####TargetName##.",
    "gclap": "##InitiatorName## ##Adverb## golf ##Infinitive::clap####TargetPreposition::at####TargetName##.",
    "gibber": "##InitiatorName## ##Adverb## ##Infinitive::gibber####TargetPreposition::at####TargetName## like a madman.",
    "giggle": "##InitiatorName## ##Infinitive::giggle## ##Adverb::happily####TargetPreposition::at####TargetName##.",
    "glare": "##InitiatorName## ##Infinitive::glare## ##Adverb::icily####TargetPreposition::at####TargetName##.",
    "gloat": "##InitiatorName## ##Infinitive::gloat## ##Adverb::foolishly####TargetPreposition::at####TargetName##.",
    "goo": "##InitiatorName## ##Adverb## ##Infinitive::goo####TargetPreposition::at####TargetName##.",
    "goose": "##InitiatorName## ##Adverb## ##Infinitive::goose####TargetName::self##!",
    "grab": "##InitiatorName## ##Adverb## ##Infinitive::grab####TargetName::at nothing in particular####TargetPreposition::by the arm##.",
    "grimace": "##InitiatorName## ##Adverb## ##Infinitive::grimace####TargetPreposition::at####TargetName##.",
    "grin": "##InitiatorName## ##Adverb## ##Infinitive::grin####TargetPreposition::at####TargetName##.",
    "groan": "##InitiatorName## ##Infinitive::groan## ##Adverb::loudly####TargetPreposition::at####TargetName##.",
    "grope": "##InitiatorName## ##Adverb## ##Infinitive::grope####TargetName::self##.",
    "grovel": "##InitiatorName## ##Infinitive::grovel## ##Adverb::shamelessly####TargetPreposition::before####TargetName##.",
    "growl": "##InitiatorName## ##Adverb## ##Infinitive::growl####TargetPreposition::at####TargetName##.",
    "grumble": "##InitiatorName## ##Adverb## ##Infinitive::grumble####TargetPreposition::at####TargetName##.",
    "guffaw": "##InitiatorName## ##Infinitive::guffaw## ##Adverb::madly####TargetPreposition::at####TargetName##.",
    "hair": "##InitiatorName## ##Infinitive::pull## out ##InitiatorPossessive## hair ##Adverb::in frustration##.",
    "handkiss": "##InitiatorName## ##Adverb::gently## ##Infinitive::take####TargetPossessive::Name::a dismembered## hand and ##Infinitive::kiss## it lightly.",
    "harumph": "##InitiatorName## ##Infinitive::harumph####TargetPreposition::at####TargetName## ##Adverb::indignantly##.",
    "hee": "##InitiatorName## ##Adverb## ##Infinitive::go## `HEE!!'##TargetPreposition::at####TargetName##.",
    "heh": "##InitiatorName## ##Infinitive::grin## ##Adverb####TargetPreposition::at####TargetName## and ##Infinitive::go##, `Heh heh heh.'",
    "hi5": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## a Hi-5!",
    "hiccup": "##InitiatorName## ##Adverb## ##Infinitive::hiccup####TargetPreposition::at####TargetName##.",
    "hmm": "##InitiatorName## ##Adverb## ##Infinitive::go## hmmm##TargetPreposition::at####TargetName##.",
    "hold": "##InitiatorName## ##Infinitive::hold####TargetName::a stuffed ogre doll## ##Adverb::closely##.",
    "hop": "##InitiatorName## ##Infinitive::hop## ##Adverb::around##.",
    "howl": "##InitiatorName## ##Infinitive::howl## ##Adverb####TargetPreposition::at####TargetName::in agony##.",
    "hrm": "##InitiatorName## ##Adverb## ##Infinitive::hrm####TargetPreposition::at####TargetName##.",
    "hug": "##InitiatorName## ##Infinitive::hug####TargetName::a stuffed ogre doll## ##Adverb::affectionately##.",
    "ignore": "##InitiatorName## ##Adverb## ##Infinitive::ignore####TargetName::the screams of the fallen##.",
    "insult": "##InitiatorName## ##Adverb## ##Infinitive::mutter## something slanderous about ##TargetName####TargetPreposition::and ##horses in physically improbable acts.",
    "jump": "##InitiatorName## ##Infinitive::jump## ##Adverb::up and down####TargetPreposition::on####TargetName##.",
    "kick": "##InitiatorName## ##Adverb## ##Infinitive::kick####TargetName::an invisible, deceased mime##.",
    "kiss": "##InitiatorName## ##Infinitive::kiss####TargetName::self## ##Adverb::affectionately##.",
    "laugh": "##InitiatorName## ##Infinitive::fall## down ##Adverb## laughing##TargetPreposition::at####TargetName##.",
    "ld": "##InitiatorName## ##Adverb## ##Infinitive::get## clobbered by linkdeath - again and again.",
    "lick": "##InitiatorName## ##Adverb## ##Infinitive::lick####TargetName::self##!",
    "lol": "##InitiatorName## ##Adverb## ##Infinitive::laugh## out loud##TargetPreposition::at####TargetName##.",
    "love": "##InitiatorName## ##Adverb## ##Infinitive::whisper## sweet words of love to##TargetName::the sky##.",
    "meh": "##InitiatorName## ##Adverb## ##Infinitive::go## `meh'##TargetPreposition::to####TargetName##.",
    "mgrin": "##InitiatorName## ##Infinitive::grin## ##Adverb::mischievously####TargetPreposition::at####TargetName##.",
    "moan": "##InitiatorName## ##Infinitive::start## ##Adverb## moaning##TargetPreposition::to####TargetName##.",
    "mock": "##InitiatorName## ##Infinitive::mock####TargetName::the accursed inanimate objects## ##Adverb::outrageously##.",
    "mstamp": "##InitiatorName## ##Adverb## ##Infinitive::slap## an official `I am a moron!' sticker on##TargetPossessive::Name::self## forehead.",
    "nibble": "##InitiatorName## ##Adverb## ##Infinitive::nibble####TargetPossessive::Name::a dead rabbit's## ear.",
    "nod": "##InitiatorName## ##Adverb## ##Infinitive::nod####TargetPreposition::at####TargetName##.",
    "nog": "##InitiatorName## ##Adverb## ##Infinitive::nog####TargetPreposition::at####TargetName##.",
    "noogie": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## a noogie.",
    "nudge": "##InitiatorName## ##Adverb## ##Infinitive::nudge####TargetName::a speck of dust##.",
    "ouch": "##InitiatorName## ##Adverb## ##Infinitive::exclaim##, `Ouch!'",
    "pace": "##InitiatorName## ##Adverb## ##Infinitive::pace## around##TargetName::the area##.",
    "panic": "##InitiatorName## ##Adverb## ##Infinitive::panic##.",
    "pat": "##InitiatorName## ##Adverb## ##Infinitive::pat####TargetName::self## on the head.",
    "peer": "##InitiatorName## ##Infinitive::peer####TargetPreposition::at####TargetName::upward## ##Adverb::quizically##.",
    "pfft": "##InitiatorName## ##Adverb## ##Infinitive::go## PFFT##TargetPreposition::at####TargetName##!",
    "pinch": "##InitiatorName## ##Adverb## ##Infinitive::pinch####TargetName::self##.",
    "pizza": "##InitiatorName## ##Infinitive::pizza####TargetPreposition::at####TargetName## ##Adverb::hungrily##.",
    "please": "##InitiatorName## ##Infinitive::make## puppy dog eyes##TargetPreposition::at####TargetName## and ##Adverb## ##Infinitive::say##, `Please?'",
    "point": "##InitiatorName## ##Adverb## ##Infinitive::point####TargetPreposition::at####TargetName::upward##.",
    "poke": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an invisible dragon## in the ribs.",
    "ponder": "##InitiatorName## ##Adverb## ##Infinitive::ponder####TargetName::the situation##.",
    "pounce": "##InitiatorName## ##Infinitive::pounce## ##Adverb::viciously####TargetPreposition::on####TargetName::toward an imaginary target, missing spectacularly##.",
    "pout": "##InitiatorName## ##Adverb## ##Infinitive::pout####TargetPreposition::at####TargetName##.",
    "puke": "##InitiatorName## ##Adverb## ##Infinitive::puke## all over##TargetName::the ground##.",
    "punch": "##InitiatorName## ##Adverb## ##Infinitive::punch####TargetName::at unseen foes##!",
    "purr": "##InitiatorName## ##Infinitive::purr## ##Adverb::contentedly####TargetPreposition::to####TargetName##.",
    "puzzle": "##InitiatorName## ##Infinitive::look## puzzled##TargetPreposition::by####TargetName##.",
    "raise": "##InitiatorName## ##Adverb## ##Infinitive::raise## an eyebrow##TargetPreposition::at####TargetName##.",
    "recoil": "##InitiatorName## ##Adverb## ##Infinitive::recoil####TargetPreposition::from####TargetName::in horror##.",
    "rofl": "##InitiatorName## ##Infinitive::roll## around on the floor ##Adverb## laughing##TargetPreposition::at####TargetName##.",
    "roll": "##InitiatorName## ##Adverb## ##Infinitive::roll## ##InitiatorPossessive## eyes##TargetPreposition::at####TargetName##.",
    "ruffle": "##InitiatorName## ##Infinitive::ruffle####TargetPossessive::Name::self## hair ##Adverb::playfully##.",
    "scratch": "##InitiatorName## ##Adverb## ##Infinitive::scratch####TargetPossessive::Name::self## head.",
    "scream": "##InitiatorName## ##Infinitive::scream## ##Adverb::loudly####TargetPreposition::at####TargetName##!",
    "shake": "##InitiatorName## ##Adverb## ##Infinitive::shake####TargetPossessive::Name::self head####TargetPreposition::hand##.",
    "shh": "##InitiatorName## ##Adverb## ##Infinitive::try## to silence##TargetName::everyone##... SHHHHHH!",
    "shiv": "##InitiatorName## ##Adverb## ##Infinitive::stab####TargetName::self## with a fake shiv.",
    "shiver": "##InitiatorName## ##Adverb## ##Infinitive::shiver####TargetPreposition::at####TargetName##.",
    "shivers": "##InitiatorName## ##Infinitive::shiver## from the cold.",
    "shrug": "##InitiatorName## ##Infinitive::shrug####TargetPreposition::at####TargetName## ##Adverb::helplessly##.",
    "shudder": "##InitiatorName## ##Adverb## ##Infinitive::shudder####TargetPreposition::at####TargetName##.",
    "sigh": "##InitiatorName## ##Infinitive::sigh## ##Adverb::deeply####TargetPreposition::at####TargetName##.",
    "slap": "##InitiatorName## ##Adverb## ##Infinitive::slap####TargetName::self##.",
    "smile": "##InitiatorName## ##Adverb## ##Infinitive::smile####TargetPreposition::at####TargetName##.",
    "smirk": "##InitiatorName## ##Adverb## ##Infinitive::smirk####TargetPreposition::at####TargetName##.",
    "smooch": "##InitiatorName## ##Adverb## ##Infinitive::smooch####TargetName::a passing harpy## with reckless abandon!",
    "snap": "##InitiatorName## ##Adverb## ##Infinitive::snap## ##InitiatorPossessive## fingers##TargetPreposition::at####TargetName##.",
    "snarl": "##InitiatorName## ##Infinitive::snarl## ##Adverb::angrily####TargetPreposition::at####TargetName##.",
    "sneeze": "##InitiatorName## ##Adverb## ##Infinitive::sneeze####TargetPreposition::at####TargetName##.",
    "snicker": "##InitiatorName## ##Adverb## ##Infinitive::snicker####TargetPreposition::at####TargetName##.",
    "sniff": "##InitiatorName## ##Adverb## ##Infinitive::sniff####TargetName##.",
    "snore": "##InitiatorName## ##Infinitive::snore## ##Adverb::loudly####TargetPreposition::at####TargetName##.",
    "snort": "##InitiatorName## ##Adverb## ##Infinitive::snort####TargetPreposition::at####TargetName##!",
    "snuggle": "##InitiatorName## ##Adverb## ##Infinitive::snuggle####TargetPreposition::up to####TargetName::with a plush dragon toy##.",
    "sob": "##InitiatorName## ##Infinitive::sob## ##Adverb::uncontrollably####TargetPreposition::to####TargetName##.",
    "spank": "##InitiatorName## ##Adverb## ##Infinitive::spank####TargetName::self##!",
    "spit": "##InitiatorName## ##Adverb## ##Infinitive::spit## on##TargetName::the ground##.",
    "squeeze": "##InitiatorName## ##Infinitive::squeeze####TargetName::self## ##Adverb::fondly##.",
    "squirm": "##InitiatorName## ##Adverb## ##Infinitive::squirm## about on the floor.",
    "stare": "##InitiatorName## ##Adverb## ##Infinitive::stare####TargetPreposition::deep into####TargetPossessive::Name####TargetPreposition::eyes##.",
    "start": "##InitiatorName## ##Infinitive::start## ##Adverb::in surprise##.",
    "seethe": "##InitiatorName## ##Adverb## ##Infinitive::seethe####TargetPreposition::at####TargetName::in silence##.",
    "stomp": "##InitiatorName## ##Adverb## ##Infinitive::stomp## ##InitiatorPossessive## foot!",
    "stretch": "##InitiatorName## ##Infinitive::stretch## ##Adverb::sleepily## and ##Infinitive::yawn##.",
    "strut": "##InitiatorName## ##Infinitive::strut## ##Adverb::proudly####TargetPreposition::at####TargetName##.",
    "sulk": "##InitiatorName## ##Adverb## ##Infinitive::sulk####TargetPreposition::to####TargetName::in the corner##.",
    "tackle": "##InitiatorName## ##Adverb## ##Infinitive::tackle####TargetName::an invisible pigmy## to the ground.",
    "tahdah": "##InitiatorName## ##Adverb## ##Infinitive::go## `Tah dah'##TargetPreposition::to####TargetName##.",
    "tap": "##InitiatorName## ##Adverb## ##Infinitive::tap####TargetPossessive::Name::self foot####TargetPreposition::shoulder##.",
    "taunt": "##InitiatorName## ##Adverb## ##Infinitive::taunt####TargetName::the world's inanimate objects##.",
    "tease": "##InitiatorName## ##Adverb## ##Infinitive::tease####TargetName::cabbage for, well, being cabbage##.",
    "thank": "##InitiatorName## ##Adverb## ##Infinitive::thank####TargetName::the world for every dead mime##.",
    "think": "##InitiatorName## ##Infinitive::think####TargetPreposition::about####TargetName## ##Adverb::carefully##.",
    "thwap": "##InitiatorName## ##Adverb## ##Infinitive::thwap####TargetName::self##.",
    "tickle": "##InitiatorName## ##Infinitive::tickle####TargetName::self## ##Adverb::playfully##.",
    "tsk": "##InitiatorName## ##Adverb## ##Infinitive::go## `tsk, tsk, tsk'##TargetPreposition::to####TargetName##.",
    "twiddle": "##InitiatorName## ##Adverb## ##Infinitive::twiddle## ##InitiatorPossessive## thumbs.",
    "twitch": "##InitiatorName## ##Adverb## ##Infinitive::twitch## ##InitiatorPossessive## left eyelid##TargetPreposition::at####TargetName##.",
    "wave": "##InitiatorName## ##Adverb## ##Infinitive::wave####TargetPreposition::at####TargetName##.",
    "weird": "##InitiatorName## ##Adverb## ##Infinitive::look####TargetPreposition::at####TargetName::at nothing in particular## and ##Infinitive::say##, `Wierdo!'",
    "well": "##InitiatorName## ##Adverb## ##Infinitive::place## ##InitiatorPossessive## hands on ##InitiatorPossessive## hips and ##Infinitive::say##, `Well?'",
    "whee": "##InitiatorName## ##Adverb## ##Infinitive::run## around screaming, `WHEEEEEE!'",
    "whine": "##InitiatorName## ##Adverb## ##Infinitive::whine####TargetPreposition::at####TargetName##.",
    "whistle": "##InitiatorName## ##Infinitive::whistle## ##Adverb::appreciatively####TargetPreposition::at####TargetName##.",
    "wiggle": "##InitiatorName## ##Adverb## ##Infinitive::wiggle## ##InitiatorPossessive## bottom##TargetPreposition::at####TargetName##.",
    "wink": "##InitiatorName## ##Infinitive::wink## ##Adverb::suggestively####TargetPreposition::at####TargetName##.",
    "worship": "##InitiatorName## ##Infinitive::fall## to the ground and ##Adverb## ##Infinitive::worship####TargetName::a dust bunny##.",
    "yawn": "##InitiatorName## ##Adverb## ##Infinitive::yawn####TargetPreposition::at####TargetName##.",
    "yay": "##InitiatorName## ##Adverb## ##Infinitive::go## `YAY'##TargetPreposition::at####TargetName##!",
    "yeah": "##InitiatorName## ##Adverb## ##Infinitive::raise## ##InitiatorPossessive## eyebrows##TargetPreposition::at####TargetName## and ##Infinitive::go##, `Yeah?'",
    "yodel": "##InitiatorName## ##Adverb## ##Infinitive::yodel## a merry tune##TargetPreposition::to####TargetName##.",
    "yuck": "##InitiatorName## ##Infinitive::look## ##Adverb## grossed out##TargetPreposition::by####TargetName##.",
    "zing": "##InitiatorName## ##Infinitive::hold## up a finger and ##Adverb## ##Infinitive::say##, `Zing!'",
]);

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Emote / Soul";
        SplitCommands = 1;
        string *emoteList = m_indices(emoteTemplates);
        foreach(string emote in emoteList)
        {
            addCommandTemplate(sprintf("%s [-a(dverb|) ##Adverb##] "
                "[-t(arget|) ##Target##] [.*]", emote));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void speakMessage(string messageTemplate,
    object initiator, object target)
{
    if (environment(initiator))
    {
        foreach(object person in all_inventory(environment(initiator)))
        {
            if (person && objectp(person))
            {
                string parsedMessage = messageTemplate;

                int colorInfo = C_SAYS;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(parsedMessage, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(parsedMessage, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(parsedMessage, "other",
                        initiator, target);
                }
                tell_object(person, formatText(parsedMessage, colorInfo,
                    person));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        string action = regreplace(command, "^([^ ]+).*", "\\1", 1);
        command = regreplace(command, action, "");
        if (sizeof(command) && !sizeof(regexp(({ command }), "[-]")))
        {
            command = "-t" + command;
        }

        string messageTemplate = emoteTemplates[action];
        if (messageTemplate)
        {
            ret = 1;
            object targetObj = 0;
            string language = 0;

            if (sizeof(regexp(({ command }), "-a(dverb)* [A-Za-z]+")))
            {
                string adverb = regreplace(command, ".*-a(dverb)* ([A-Za-z]+).*", "\\2", 1);
                command = regreplace(command, " *-a(dverb)* ([A-Za-z]+)", "", 1);
                messageTemplate = regreplace(messageTemplate, "##Adverb(::[^#]+)*##", adverb);
            }
            else
            {
                messageTemplate = regreplace(messageTemplate, "##Adverb(::)*([^#]+)*##", "\\2", 1);
            }

            if (sizeof(regexp(({ command }), "-t(arget)* '*[A-Za-z]+")))
            {
                string target = regreplace(command, ".*-t(arget)* ([A-Za-z]+|'[^']+').*", "\\2", 1);
                target = regreplace(target, "'([^']+)'", "\\1", 1);
                targetObj = present(target, environment(initiator));
                command = regreplace(command, "-t(arget)* ([A-Za-z]+)", "", 1);
                command = regreplace(command, "-t(arget)* ('[A-Za-z ]+')", "", 1);

                messageTemplate = regreplace(messageTemplate, "##Target", " ##Target", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetName(::[^#]+)*##", "##TargetName##", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetPossessive::Name(::[^#]+)*##", "##TargetPossessive::Name##", 1);
                if (!targetObj)
                {
                    messageTemplate = regreplace(messageTemplate, "##TargetName##", target);
                }
                messageTemplate = regreplace(messageTemplate, "##TargetPreposition::([^#]+)##", "\\1", 1);
                messageTemplate = regreplace(messageTemplate, " ([,;.!?] )", "\\1", 1);
            }
            else
            {
                messageTemplate = regreplace(messageTemplate, "##TargetName::self##", " ##InitiatorReflexive##", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetName::([^#]+)*##", " \\1", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetPossessive::Name::self([^#]+)*##", " ##InitiatorPossessive##\\1", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetPossessive::Name::([^#]+)*##", " \\1", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetPreposition::[^#]+##", "", 1);
                messageTemplate = regreplace(messageTemplate, "##Target[^#]+##", "");
            }

            // This will kill the other flags
            string commandList = "(" + implode(m_indices(emoteTemplates), "|") + ")";
            if (sizeof(regexp(({ action + command }), commandList + " -[A-Za-z]+")))
            {
                string flag = regreplace(action + command, commandList + " (-[A-Za-z]+).*", "\\2", 1);
                tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
            }
            else
            {
                speakMessage(messageTemplate, initiator, targetObj);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayUsageDetails(string displayCommand)
{
    string ret = "";

    if (sizeof(commands) && member(emoteTemplates, displayCommand))
    {
        string *commandText = ({});
        commandText += ({ regreplace(displayCommand, "##([^#]+)##", "<\\1>", 1) });
        ret = implode(commandText, "\n                  ");
    }

    return ret;
}
