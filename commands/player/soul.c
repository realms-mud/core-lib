//******************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include <mtypes.h>

mapping emoteTemplates = ([
    "ack": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::ack####TargetPreposition::at####TargetName##.",
    ]),
    "admire": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::admire####TargetName::the ambiguity of admiring without a target##.",
        "reactions": ([
            "opinion modifier": 5,
        ]),
    ]),
    "agree": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::agree####TargetPreposition::with####TargetName##.", 
    ]),
    "agrin": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grin####TargetPreposition::at####TargetName## like an ass.", 
    ]),
    "aha": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## 'Aha!'##TargetPreposition::at####TargetName##.", 
    ]),
    "ahh": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## AHHH##TargetPreposition::at####TargetName##.", 
    ]),
    "amorous": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::feel## amorous##TargetPreposition::toward####TargetName##.", 
    ]),
    "annoy": ([ 
        "template": "##InitiatorName## ##Infinitive::be## ##Adverb## annoying##TargetName##.", 
    ]),
    "apologize": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::apologize####TargetPreposition::to####TargetName##.", 
    ]),
    "applaud": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give## a round of applause##TargetPreposition::to####TargetName##.", 
    ]),
    "ayt": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::wave## ##InitiatorPossessive## hand back and forth##TargetPreposition::in front of####TargetName## and ##Infinitive::say##, 'Are you there?'", 
    ]),
    "backhand": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::backhand####TargetName::an invisible, deceased llama##.", 
    ]),
    "baha": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## BAHAHAHA##TargetPreposition::at####TargetName##.", 
    ]),
    "bark": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bark## like a dog##TargetPreposition::at####TargetName##.", 
    ]),
    "breakdance": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::breakdance## like a madman##TargetPreposition::around####TargetName##.", 
    ]),
    "beam": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::beam## like a lightbulb.", 
    ]),
    "beep": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::beep####TargetName::like a person mercilessly spared from the ravages of sanity.####TargetPreposition::on the nose.##", 
    ]),
    "beg": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::beg## like a dog##TargetPreposition::at####TargetName##.", 
    ]),
    "bleed": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bleed##.", 
    ]),
    "blink": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::blink####TargetPreposition::at####TargetName##.", 
    ]),
    "blush": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::blush####TargetPreposition::while looking at####TargetName##.", 
    ]),
    "boggle": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::boggle####TargetPreposition::at####TargetName::at the concept##.", 
    ]),
    "boo": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snarl####TargetPreposition::behind####TargetName::BOO! HISS####TargetPreposition::scaring the $%!@ out of####TargetObjective##!", 
    ]),
    "boot": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::an imaginary mime## a boot to the head!", 
    ]),
    "bootie": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shake## ##InitiatorPossessive## bootie!", 
    ]),
    "bop": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bop####TargetName::an invisible flying turtle##!", 
    ]),
    "bored": ([ 
        "template": "##InitiatorName## ##Infinitive::be## ##Adverb## bored##TargetPreposition::with####TargetName##.",
    ]),
    "bounce": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bounce## up and down.",
    ]),
    "bow": ([
        "template": "##InitiatorName## ##Infinitive::bow####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
    ]),
    "bpoke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an imaginary sea otter## and ##Infinitive::sneer##, 'Does this bug you?'",
    ]),
    "brb": ([
        "template": "##InitiatorName## ##Adverb## will be right back (after a word from ##InitiatorPossessive## sponsors).",
    ]),
    "breathe": ([
        "template": "##InitiatorName## ##Infinitive::breathe## ##Adverb::deeply##.",
    ]),
    "bsigh": ([
        "template": "##InitiatorName## ##Infinitive::sigh## ##Adverb::indignantly## ##TargetPreposition::at####TargetName## and ##Infinitive::mutter##, `I'm bitter!'",
    ]),
    "bullshit": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::think## that is bullshit!",
    ]),
    "burp": ([
        "template": "##InitiatorName## ##Infinitive::burp## ##Adverb::rudely##.",
    ]),
    "cackle": ([
        "template": "##InitiatorName## ##Infinitive::throw## ##InitiatorPossessive## head back and ##Infinitive::cackle####TargetPreposition::at####TargetName## ##Adverb::with glee##!",
    ]),
    "caress": ([
        "template": "##InitiatorName## ##Adverb::gently## ##Infinitive::run## ##InitiatorPossessive## finger down ##TargetPossessive::Name::an invisible, deaf mime's## cheek.",
    ]),
    "cheer": ([
        "template": "##InitiatorName## ##Infinitive::cheer## ##Adverb::enthusiastically####TargetPreposition::at####TargetName##.",
    ]),
    "cherry": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gobble## up a bowl of cherries.",
    ]),
    "chew": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::chew## on something.",
    ]),
    "chirp": ([
        "template": "##InitiatorName## ##Infinitive::chirp## ##Adverb::merrily####TargetPreposition::at####TargetName##.",
    ]),
    "choke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::choke####TargetName##.",
    ]),
    "chortle": ([
        "template": "##InitiatorName## ##Infinitive::chortle## ##Adverb::gleefully####TargetPreposition::at####TargetName##.",
    ]),
    "chuckle": ([
        "template": "##InitiatorName## ##Infinitive::chuckle## ##Adverb::politely####TargetPreposition::at####TargetName##.",
    ]),
    "clap": ([
        "template": "##InitiatorName## ##Infinitive::clap## ##Adverb::briefly####TargetPreposition::to####TargetName##.",
    ]),
    "comfort": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::comfort####TargetName::a small rock##.",
    ]),
    "congratulate": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::congratulate####TargetName::self## on a job well done.",
    ]),
    "cough": ([
        "template": "##InitiatorName## ##Infinitive::cough## ##Adverb::noisily####TargetPreposition::at####TargetName##.",
    ]),
    "cower": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::cower####TargetPreposition::from####TargetName::in a corner##.",
    ]),
    "crack": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::crack## ##InitiatorPossessive## knuckles.",
    ]),
    "cringe": ([
        "template": "##InitiatorName## ##Infinitive::cringe## ##Adverb::in terror####TargetPreposition::from####TargetName##.", 
    ]),
    "cross": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::cross## ##InitiatorPossessive## fingers.",
    ]),
    "cry": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::burst## into tears.",
    ]),
    "cuddle": ([
        "template": "##InitiatorName## ##Infinitive::cuddle####TargetName::self## ##Adverb::tenderly##.",
    ]),
    "curtsey": ([
        "template": "##InitiatorName## ##Infinitive::curtsey####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
    ]),
    "dammit": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::say##, `DAMMIT!'##TargetPreposition::to####TargetName##.",
    ]),
    "dance": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::dance####TargetPreposition::with####TargetName::happily####TargetPreposition::, sweeping ####TargetObjective####TargetPreposition::across the dance floor##.",
    ]),
    "daydream": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::get## lost in a daydream##TargetPreposition::about####TargetName##.",
    ]),
    "die": ([
        "template": "##InitiatorName## ##Infinitive::roll## over ##Adverb## and ##Infinitive::do## ##InitiatorPossessive## best to look dead.",
    ]),
    "disagree": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::disagree####TargetPreposition::with####TargetName##.",
    ]),
    "doh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smack## ##InitiatorPossessive## head and ##Infinitive::go##, `Doh!'",
    ]),
    "drool": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::drool## all over##TargetName::self##.",
    ]),
    "duck": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::duck## out of the way.",
    ]),
    "duh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::scream## `DUH!'##TargetPreposition::at####TargetName##.",
    ]),
    "eek": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## 'eeeeeeeeeeeeek!'##TargetPreposition::to####TargetName##.",
    ]),
    "eep": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## 'EEEEP!'##TargetPreposition::to####TargetName##.",
    ]),
    "egrin": ([
        "template": "##InitiatorName## ##Infinitive::grin## ##Adverb::evilly####TargetPreposition::at####TargetName##.",
    ]),
    "eh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::say##, `EH?'",
    ]),
    "embarrass": ([
        "template": "##InitiatorName## ##Infinitive::be## ##Adverb::really## embarrassed!",
    ]),
    "embrace": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gather####TargetName::self## in a warm, loving embrace.",
    ]),
    "explode": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::explode####TargetPreposition::at####TargetName::all over the room##!",
    ]),
    "faint": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::faint##... THUMP!",
    ]),
    "fart": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::let## off a real rip-roarer##TargetPreposition::at####TargetName##.",
    ]),
    "fear": ([
        "template": "##InitiatorName## ##Infinitive::shiver## ##Adverb## with fear##TargetPreposition::from####TargetName##.",
    ]),
    "flash": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::strip## ##InitiatorPossessive## clothes and ##Infinitive::bare## ##InitiatorPossessive## body for all to see!",
    ]),
    "flex": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flex## ##InitiatorPossessive## muscles##TargetPreposition::at####TargetName##!",
    ]),
    "flip": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flip## head over heels.",
    ]),
    "flipoff": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## the finger!",
    ]),
    "flirt": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flirt####TargetPreposition::with####TargetName::with disaster##.",
    ]),
    "flog": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flog####TargetName::an invisible, mute mime##!",
    ]),
    "flop": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flop## to the floor... FLOP!",
    ]),
    "fly": ([
        "template": "##InitiatorName## ##Infinitive::put## out ##InitiatorPossessive## arms ##Adverb## and ##Infinitive::run## around like a flying bird.",
    ]),
    "fondle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::fondle####TargetName::self##.",
    ]),
    "freeze": ([
        "template": "##InitiatorName## ##Infinitive::freeze## ##Adverb## and ##Infinitive::turn## into a popsicle!",
    ]),
    "french": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::an invisible toad## a deep, hot, passionate kiss...it seems to last forever.",
    ]),
    "frown": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::frown####TargetPreposition::at####TargetName##.",
    ]),
    "fume": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::fume####TargetPreposition::at####TargetName##.",
    ]),
    "gag": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gag####TargetPreposition::at####TargetName##.",
    ]),
    "gasp": ([
        "template": "##InitiatorName## ##Infinitive::gasp## ##Adverb::in astonishment####TargetPreposition::at####TargetName##.",
    ]),
    "gclap": ([
        "template": "##InitiatorName## ##Adverb## golf ##Infinitive::clap####TargetPreposition::at####TargetName##.",
    ]),
    "gibber": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gibber####TargetPreposition::at####TargetName## like a madman.",
    ]),
    "giggle": ([
        "template": "##InitiatorName## ##Infinitive::giggle## ##Adverb::happily####TargetPreposition::at####TargetName##.",
    ]),
    "glare": ([
        "template": "##InitiatorName## ##Infinitive::glare## ##Adverb::icily####TargetPreposition::at####TargetName##.",
    ]),
    "gloat": ([
        "template": "##InitiatorName## ##Infinitive::gloat## ##Adverb::foolishly####TargetPreposition::at####TargetName##.",
    ]),
    "goo": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::goo####TargetPreposition::at####TargetName##.",
    ]),
    "goose": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::goose####TargetName::self##!",
    ]),
    "grab": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grab####TargetName::at nothing in particular####TargetPreposition::by the arm##.",
    ]),
    "grimace": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grimace####TargetPreposition::at####TargetName##.",
    ]),
    "grin": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grin####TargetPreposition::at####TargetName##.",
    ]),
    "groan": ([
        "template": "##InitiatorName## ##Infinitive::groan## ##Adverb::loudly####TargetPreposition::at####TargetName##.",
    ]),
    "grope": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grope####TargetName::self##.",
    ]),
    "grovel": ([
        "template": "##InitiatorName## ##Infinitive::grovel## ##Adverb::shamelessly####TargetPreposition::before####TargetName##.",
    ]),
    "growl": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::growl####TargetPreposition::at####TargetName##.",
    ]),
    "grumble": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grumble####TargetPreposition::at####TargetName##.",
    ]),
    "guffaw": ([
        "template": "##InitiatorName## ##Infinitive::guffaw## ##Adverb::madly####TargetPreposition::at####TargetName##.",
    ]),
    "hair": ([
        "template": "##InitiatorName## ##Infinitive::pull## out ##InitiatorPossessive## hair ##Adverb::in frustration##.",
    ]),
    "handkiss": ([
        "template": "##InitiatorName## ##Adverb::gently## ##Infinitive::take####TargetPossessive::Name::a dismembered## hand and ##Infinitive::kiss## it lightly.",
    ]),
    "harumph": ([
        "template": "##InitiatorName## ##Infinitive::harumph####TargetPreposition::at####TargetName## ##Adverb::indignantly##.",
    ]),
    "hee": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## `HEE!!'##TargetPreposition::at####TargetName##.",
    ]),
    "heh": ([
        "template": "##InitiatorName## ##Infinitive::grin## ##Adverb####TargetPreposition::at####TargetName## and ##Infinitive::go##, `Heh heh heh.'",
    ]),
    "hi5": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## a Hi-5!",
    ]),
    "hiccup": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::hiccup####TargetPreposition::at####TargetName##.",
    ]),
    "hmm": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## hmmm##TargetPreposition::at####TargetName##.",
    ]),
    "hold": ([
        "template": "##InitiatorName## ##Infinitive::hold####TargetName::a stuffed ogre doll## ##Adverb::closely##.",
    ]),
    "hop": ([
        "template": "##InitiatorName## ##Infinitive::hop## ##Adverb::around##.",
    ]),
    "howl": ([
        "template": "##InitiatorName## ##Infinitive::howl## ##Adverb####TargetPreposition::at####TargetName::in agony##.",
    ]),
    "hrm": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::hrm####TargetPreposition::at####TargetName##.",
    ]),
    "hug": ([
        "template": "##InitiatorName## ##Infinitive::hug####TargetName::a stuffed ogre doll## ##Adverb::affectionately##.",
    ]),
    "ignore": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::ignore####TargetName::the screams of the fallen##.",
    ]),
    "insult": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::mutter## something slanderous about ##TargetName####TargetPreposition::and ##horses in physically improbable acts.",
    ]),
    "jump": ([
        "template": "##InitiatorName## ##Infinitive::jump## ##Adverb::up and down####TargetPreposition::on####TargetName##.",
    ]),
    "kick": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::kick####TargetName::an invisible, deceased mime##.",
    ]),
    "kiss": ([
        "template": "##InitiatorName## ##Infinitive::kiss####TargetName::self## ##Adverb::affectionately##.",
    ]),
    "laugh": ([
        "template": "##InitiatorName## ##Infinitive::fall## down ##Adverb## laughing##TargetPreposition::at####TargetName##.",
    ]),
    "ld": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::get## clobbered by linkdeath - again and again.",
    ]),
    "lick": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::lick####TargetName::self##!",
    ]),
    "lol": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::laugh## out loud##TargetPreposition::at####TargetName##.",
    ]),
    "love": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::whisper## sweet words of love to##TargetName::the sky##.",
    ]),
    "meh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## `meh'##TargetPreposition::to####TargetName##.",
    ]),
    "mgrin": ([
        "template": "##InitiatorName## ##Infinitive::grin## ##Adverb::mischievously####TargetPreposition::at####TargetName##.",
    ]),
    "moan": ([
        "template": "##InitiatorName## ##Infinitive::start## ##Adverb## moaning##TargetPreposition::to####TargetName##.",
    ]),
    "mock": ([
        "template": "##InitiatorName## ##Infinitive::mock####TargetName::the accursed inanimate objects## ##Adverb::outrageously##.",
    ]),
    "mstamp": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::slap## an official `I am a moron!' sticker on##TargetPossessive::Name::self## forehead.",
    ]),
    "nibble": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nibble####TargetPossessive::Name::a dead rabbit's## ear.",
    ]),
    "nod": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nod####TargetPreposition::at####TargetName##.",
    ]),
    "nog": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nog####TargetPreposition::at####TargetName##.",
    ]),
    "noogie": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## a noogie.",
    ]),
    "nudge": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nudge####TargetName::a speck of dust##.",
    ]),
    "ouch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::exclaim##, `Ouch!'",
    ]),
    "pace": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::pace## around##TargetName::the area##.",
    ]),
    "panic": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::panic##.",
    ]),
    "pat": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::pat####TargetName::self## on the head.",
    ]),
    "peer": ([
        "template": "##InitiatorName## ##Infinitive::peer####TargetPreposition::at####TargetName::upward## ##Adverb::quizically##.",
    ]),
    "pfft": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## PFFT##TargetPreposition::at####TargetName##!",
    ]),
    "pinch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::pinch####TargetName::self##.",
    ]),
    "pizza": ([
        "template": "##InitiatorName## ##Infinitive::pizza####TargetPreposition::at####TargetName## ##Adverb::hungrily##.",
    ]),
    "please": ([
        "template": "##InitiatorName## ##Infinitive::make## puppy dog eyes##TargetPreposition::at####TargetName## and ##Adverb## ##Infinitive::say##, `Please?'",
    ]),
    "point": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::point####TargetPreposition::at####TargetName::upward##.",
    ]),
    "poke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an invisible dragon## in the ribs.",
    ]),
    "ponder": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::ponder####TargetName::the situation##.",
    ]),
    "pounce": ([
        "template": "##InitiatorName## ##Infinitive::pounce## ##Adverb::viciously####TargetPreposition::on####TargetName::toward an imaginary target, missing spectacularly##.",
    ]),
    "pout": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::pout####TargetPreposition::at####TargetName##.",
    ]),
    "puke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::puke## all over##TargetName::the ground##.",
    ]),
    "punch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::punch####TargetName::at unseen foes##!",
    ]),
    "purr": ([
        "template": "##InitiatorName## ##Infinitive::purr## ##Adverb::contentedly####TargetPreposition::to####TargetName##.",
    ]),
    "puzzle": ([
        "template": "##InitiatorName## ##Infinitive::look## puzzled##TargetPreposition::by####TargetName##.",
    ]),
    "raise": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::raise## an eyebrow##TargetPreposition::at####TargetName##.",
    ]),
    "recoil": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::recoil####TargetPreposition::from####TargetName::in horror##.",
    ]),
    "rofl": ([
        "template": "##InitiatorName## ##Infinitive::roll## around on the floor ##Adverb## laughing##TargetPreposition::at####TargetName##.",
    ]),
    "roll": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::roll## ##InitiatorPossessive## eyes##TargetPreposition::at####TargetName##.",
    ]),
    "ruffle": ([
        "template": "##InitiatorName## ##Infinitive::ruffle####TargetPossessive::Name::self## hair ##Adverb::playfully##.",
    ]),
    "scratch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::scratch####TargetPossessive::Name::self## head.",
    ]),
    "scream": ([
        "template": "##InitiatorName## ##Infinitive::scream## ##Adverb::loudly####TargetPreposition::at####TargetName##!",
    ]),
    "shake": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shake####TargetPossessive::Name::self head####TargetPreposition::hand##.",
    ]),
    "shh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::try## to silence##TargetName::everyone##... SHHHHHH!",
    ]),
    "shiv": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::stab####TargetName::self## with a fake shiv.",
    ]),
    "shiver": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shiver####TargetPreposition::at####TargetName##.",
    ]),
    "shivers": ([
        "template": "##InitiatorName## ##Infinitive::shiver## from the cold.",
    ]),
    "shrug": ([
        "template": "##InitiatorName## ##Infinitive::shrug####TargetPreposition::at####TargetName## ##Adverb::helplessly##.",
    ]),
    "shudder": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shudder####TargetPreposition::at####TargetName##.",
    ]),
    "sigh": ([
        "template": "##InitiatorName## ##Infinitive::sigh## ##Adverb::deeply####TargetPreposition::at####TargetName##.",
    ]),
    "slap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::slap####TargetName::self##.",
    ]),
    "smile": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smile####TargetPreposition::at####TargetName##.",
    ]),
    "smirk": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smirk####TargetPreposition::at####TargetName##.",
    ]),
    "smooch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smooch####TargetName::a passing harpy## with reckless abandon!",
    ]),
    "snap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snap## ##InitiatorPossessive## fingers##TargetPreposition::at####TargetName##.",
    ]),
    "snarl": ([
        "template": "##InitiatorName## ##Infinitive::snarl## ##Adverb::angrily####TargetPreposition::at####TargetName##.",
    ]),
    "sneeze": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::sneeze####TargetPreposition::at####TargetName##.",
    ]),
    "snicker": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snicker####TargetPreposition::at####TargetName##.",
    ]),
    "sniff": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::sniff####TargetName##.",
    ]),
    "snore": ([
        "template": "##InitiatorName## ##Infinitive::snore## ##Adverb::loudly####TargetPreposition::at####TargetName##.",
    ]),
    "snort": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snort####TargetPreposition::at####TargetName##!",
    ]),
    "snuggle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snuggle####TargetPreposition::up to####TargetName::with a plush dragon toy##.",
    ]),
    "sob": ([
        "template": "##InitiatorName## ##Infinitive::sob## ##Adverb::uncontrollably####TargetPreposition::to####TargetName##.",
    ]),
    "spank": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::spank####TargetName::self##!",
    ]),
    "spit": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::spit## on##TargetName::the ground##.",
    ]),
    "squeeze": ([
        "template": "##InitiatorName## ##Infinitive::squeeze####TargetName::self## ##Adverb::fondly##.",
    ]),
    "squirm": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::squirm## about on the floor.",
    ]),
    "stare": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::stare####TargetPreposition::deep into####TargetPossessive::Name####TargetPreposition::eyes##.",
    ]),
    "start": ([
        "template": "##InitiatorName## ##Infinitive::start## ##Adverb::in surprise##.",
    ]),
    "seethe": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::seethe####TargetPreposition::at####TargetName::in silence##.",
    ]),
    "stomp": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::stomp## ##InitiatorPossessive## foot!",
    ]),
    "stretch": ([
        "template": "##InitiatorName## ##Infinitive::stretch## ##Adverb::sleepily## and ##Infinitive::yawn##.",
    ]),
    "strut": ([
        "template": "##InitiatorName## ##Infinitive::strut## ##Adverb::proudly####TargetPreposition::at####TargetName##.",
    ]),
    "sulk": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::sulk####TargetPreposition::to####TargetName::in the corner##.",
    ]),
    "tackle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::tackle####TargetName::an invisible pigmy## to the ground.",
    ]),
    "tahdah": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## `Tah dah'##TargetPreposition::to####TargetName##.",
    ]),
    "tap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::tap####TargetPossessive::Name::self foot####TargetPreposition::shoulder##.",
    ]),
    "taunt": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::taunt####TargetName::the world's inanimate objects##.",
    ]),
    "tease": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::tease####TargetName::cabbage for, well, being cabbage##.",
    ]),
    "thank": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::thank####TargetName::the world for every dead mime##.",
    ]),
    "think": ([
        "template": "##InitiatorName## ##Infinitive::think####TargetPreposition::about####TargetName## ##Adverb::carefully##.",
    ]),
    "thwap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::thwap####TargetName::self##.",
    ]),
    "tickle": ([
        "template": "##InitiatorName## ##Infinitive::tickle####TargetName::self## ##Adverb::playfully##.",
    ]),
    "tsk": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## `tsk, tsk, tsk'##TargetPreposition::to####TargetName##.",
    ]),
    "twiddle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::twiddle## ##InitiatorPossessive## thumbs.",
    ]),
    "twitch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::twitch## ##InitiatorPossessive## left eyelid##TargetPreposition::at####TargetName##.",
    ]),
    "wave": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::wave####TargetPreposition::at####TargetName##.",
    ]),
    "weird": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::look####TargetPreposition::at####TargetName::at nothing in particular## and ##Infinitive::say##, `Wierdo!'",
    ]),
    "well": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::place## ##InitiatorPossessive## hands on ##InitiatorPossessive## hips and ##Infinitive::say##, `Well?'",
    ]),
    "whee": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::run## around screaming, `WHEEEEEE!'",
    ]),
    "whine": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::whine####TargetPreposition::at####TargetName##.",
    ]),
    "whistle": ([
        "template": "##InitiatorName## ##Infinitive::whistle## ##Adverb::appreciatively####TargetPreposition::at####TargetName##.",
    ]),
    "wiggle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::wiggle## ##InitiatorPossessive## bottom##TargetPreposition::at####TargetName##.",
    ]),
    "wink": ([
        "template": "##InitiatorName## ##Infinitive::wink## ##Adverb::suggestively####TargetPreposition::at####TargetName##.",
    ]),
    "worship": ([
        "template": "##InitiatorName## ##Infinitive::fall## to the ground and ##Adverb## ##Infinitive::worship####TargetName::a dust bunny##.",
    ]),
    "yawn": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::yawn####TargetPreposition::at####TargetName##.",
    ]),
    "yay": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## `YAY'##TargetPreposition::at####TargetName##!",
    ]),
    "yeah": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::raise## ##InitiatorPossessive## eyebrows##TargetPreposition::at####TargetName## and ##Infinitive::go##, `Yeah?'",
    ]),
    "yodel": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::yodel## a merry tune##TargetPreposition::to####TargetName##.",
    ]),
    "yuck": ([
        "template": "##InitiatorName## ##Infinitive::look## ##Adverb## grossed out##TargetPreposition::by####TargetName##.",
    ]),
    "zing": ([
        "template": "##InitiatorName## ##Infinitive::hold## up a finger and ##Adverb## ##Infinitive::say##, `Zing!'",
    ]),
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

        string messageTemplate = emoteTemplates[action]["template"];
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

                if (targetObj && (initiator != targetObj) && 
                    member(emoteTemplates[action], "value"))
                {
                    targetObj->alterOpinionFromEmote(initiator,
                        emoteTemplates[action]);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string usageDetails(string displayCommand)
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
