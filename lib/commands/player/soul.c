//******************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

mapping emoteTemplates = ([
    "ack": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::ack####TargetPreposition::at####TargetName##.",
    ]),
    "admire": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::admire####TargetName::the ambiguity of admiring without a target##.",
        "reactions": ([
            "opinion modifier": 3,
        ]),
    ]),
    "agree": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::agree####TargetPreposition::with####TargetName##.", 
        "reactions": ([
            "opinion modifier": 1,
        ]),
        "can self-target": 1,
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
        "reactions": ([
            "romance action": 1,
            "opinion modifier": 5,
        ]),
    ]),
    "annoy": ([ 
        "template": "##InitiatorName## ##Infinitive::be## ##Adverb## annoying##TargetName##.", 
        "reactions": ([
            "opinion modifier": -1,
        ]),
    ]),
    "apologize": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::apologize####TargetPreposition::to####TargetName##.", 
        "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "applaud": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give## a round of applause##TargetPreposition::to####TargetName##.", 
        "can self-target": 1,
    ]),
    "ayt": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::wave## ##InitiatorPossessive## hand back and forth##TargetPreposition::in front of####TargetName## and ##Infinitive::say##, 'Are you there?'", 
    ]),
    "backhand": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::backhand####TargetName::an invisible, deceased llama##.", 
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -10,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName##."
        ]),
    ]),
    "baha": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## BAHAHAHA##TargetPreposition::at####TargetName##.", 
        "reactions": ([
            "opinion modifier": -1,
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "opinion modifier": -1,
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -10,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the jaw."
        ]),
    ]),
    "bootie": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shake## ##InitiatorPossessive## bootie!", 
    ]),
    "bop": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bop####TargetName::an invisible flying turtle##!", 
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::bop## ##TargetName##."
        ]),
    ]),
    "bored": ([ 
        "template": "##InitiatorName## ##Infinitive::be## ##Adverb## bored##TargetPreposition::with####TargetName##.",
    ]),
    "bounce": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::bounce## up and down.",
    ]),
    "bow": ([
        "template": "##InitiatorName## ##Infinitive::bow####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
         "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "bpoke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an imaginary sea otter## and ##Infinitive::sneer##, 'Does this bug you?'",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -1,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the groin and ##Infinitive::sneer##, 'Did that bug you?'"
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 10,
            "retaliation": "##InitiatorName## ##Infinitive::push## ##TargetName## away.",
            "reciprocation": "##InitiatorName## ##Infinitive::smile## at ##TargetName##."
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the jaw."
        ]),
    ]),
    "chortle": ([
        "template": "##InitiatorName## ##Infinitive::chortle## ##Adverb::gleefully####TargetPreposition::at####TargetName##.",
    ]),
    "chuckle": ([
        "template": "##InitiatorName## ##Infinitive::chuckle## ##Adverb::politely####TargetPreposition::at####TargetName##.",
    ]),
    "clap": ([
        "template": "##InitiatorName## ##Infinitive::clap## ##Adverb::briefly####TargetPreposition::to####TargetName##.",
        "can self-target": 1,
    ]),
    "comfort": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::comfort####TargetName::a small rock##.",
        "reactions": ([
            "opinion modifier": 5,
        ]),
    ]),
    "congratulate": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::congratulate####TargetName::self## on a job well done.",
        "reactions": ([
            "opinion modifier": 1,
        ]),
        "can self-target": 1,
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 10,
            "retaliation": "##InitiatorName## ##Infinitive::push## ##TargetName## away.",
            "reciprocation": "##InitiatorName## ##Infinitive::kiss## ##TargetName## tenderly."
        ]),
    ]),
    "curtsey": ([
        "template": "##InitiatorName## ##Infinitive::curtsey####TargetPreposition::to####TargetName## ##Adverb::gracefully##.",
        "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "dammit": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::say##, `DAMMIT!'##TargetPreposition::to####TargetName##.",
    ]),
    "dance": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::dance####TargetPreposition::with####TargetName::happily####TargetPreposition::, sweeping ####TargetObjective####TargetPreposition::across the dance floor##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 2,
        ]),
    ]),
    "daydream": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::get## lost in a daydream##TargetPreposition::about####TargetName##.",
        "reactions": ([
            "romance action": 1,
            "opinion modifier": 2,
        ]),
        "can self-target": 1,
    ]),
    "die": ([
        "template": "##InitiatorName## ##Infinitive::roll## over ##Adverb## and ##Infinitive::do## ##InitiatorPossessive## best to look dead.",
    ]),
    "disagree": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::disagree####TargetPreposition::with####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
        "can self-target": 1,
    ]),
    "doh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smack## ##InitiatorPossessive## head and ##Infinitive::go##, `Doh!'",
    ]),
    "drool": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::drool## all over##TargetName::self##.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -2,
        ]),
        "can self-target": 1,
    ]),
    "duck": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::duck## out of the way.",
    ]),
    "duh": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::scream## `DUH!'##TargetPreposition::at####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
        "can self-target": 1,
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 15,
            "retaliation": "##InitiatorName## ##Infinitive::push## ##TargetName## away.",
            "reciprocation": "##InitiatorName## gently ##Infinitive::kiss## ##TargetName##."
        ]),
    ]),
    "explode": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::explode####TargetPreposition::at####TargetName::all over the room##!",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -2,
        ]),
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
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -25,
        ]),
    ]),
    "flex": ([ 
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flex## ##InitiatorPossessive## muscles##TargetPreposition::at####TargetName##!",
    ]),
    "flip": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flip## head over heels.",
    ]),
    "flipoff": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## the finger!",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
    ]),
    "flirt": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flirt####TargetPreposition::with####TargetName::with disaster##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::reply## to ##TargetName##, `You can stop that.'",
            "reciprocation": "##InitiatorName## ##Infinitive::smile## at ##TargetName##."
       ]),
    ]),
    "flog": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flog####TargetName::an invisible, mute mime##!",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -10,
        ]),
    ]),
    "flop": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::flop## to the floor... FLOP!",
    ]),
    "fly": ([
        "template": "##InitiatorName## ##Infinitive::put## out ##InitiatorPossessive## arms ##Adverb## and ##Infinitive::run## around like a flying bird.",
    ]),
    "fondle": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::fondle####TargetName::self##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 10,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin and ##Infinitive::scream##, `How dare you?'",
            "reciprocation": "##InitiatorName## playfully ##Infinitive::moan## at ##TargetName##."
        ]),
        "can self-target": 1,
    ]),
    "freeze": ([
        "template": "##InitiatorName## ##Infinitive::freeze## ##Adverb## and ##Infinitive::turn## into a popsicle!",
    ]),
    "french": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::an invisible toad## a deep, hot, passionate kiss...it seems to last forever.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 20,
            "retaliation": "##InitiatorName## ##Infinitive::push## ##TargetName## away and ##Infinitive::snarl##, `Stay away from me!'",
            "reciprocation": "##InitiatorName## playfully ##Infinitive::nibble## ##TargetPossessive::Name## tongue as they pull away."
        ]),
    ]),
    "frown": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::frown####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -1,
        ]),
    ]),
    "fume": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::fume####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
    ]),
    "gag": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gag####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -2,
        ]),
    ]),
    "gasp": ([
        "template": "##InitiatorName## ##Infinitive::gasp## ##Adverb::in astonishment####TargetPreposition::at####TargetName##.",
    ]),
    "gclap": ([
        "template": "##InitiatorName## ##Adverb## golf ##Infinitive::clap####TargetPreposition::at####TargetName##.",
        "can self-target": 1,
    ]),
    "gibber": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::gibber####TargetPreposition::at####TargetName## like a madman.",
    ]),
    "giggle": ([
        "template": "##InitiatorName## ##Infinitive::giggle## ##Adverb::happily####TargetPreposition::at####TargetName##.",
    ]),
    "glare": ([
        "template": "##InitiatorName## ##Infinitive::glare## ##Adverb::icily####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -1,
        ]),
    ]),
    "gloat": ([
        "template": "##InitiatorName## ##Infinitive::gloat## ##Adverb::foolishly####TargetPreposition::at####TargetName##.",
         "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
    ]),
    "goo": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::goo####TargetPreposition::at####TargetName##.",
    ]),
    "goose": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::goose####TargetName::self##!",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
        ]),
    ]),
    "grab": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::grab####TargetName::at nothing in particular####TargetPreposition::by the arm##.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -1,
         ]),
         "can self-target": 1,
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 10,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin and ##Infinitive::scream##, `Asshole!'",
            "reciprocation": "##InitiatorName## ##Infinitive::grope## ##TargetName##."
        ]),
    ]),
    "grovel": ([
        "template": "##InitiatorName## ##Infinitive::grovel## ##Adverb::shamelessly####TargetPreposition::before####TargetName##.",
         "reactions": ([
            "opinion modifier": 1,
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::pull## ##InitiatorPossessive## hand away from ##TargetName## and ##Infinitive::say##, `What's wrong with you?'",
            "reciprocation": "##InitiatorName## ##Infinitive::blush## at ##TargetName##."
        ]),
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
         "reactions": ([
            "can be blocked": 1,
        ]),
    ]),
    "hiccup": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::hiccup####TargetPreposition::at####TargetName##.",
    ]),
    "hmm": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## hmmm##TargetPreposition::at####TargetName##.",
    ]),
    "hold": ([
        "template": "##InitiatorName## ##Infinitive::hold####TargetName::a stuffed ogre doll## ##Adverb::closely##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin ##Infinitive::snarl##, `Release me, jackwagon!'",
            "reciprocation": "##InitiatorName## gently ##Infinitive::kiss## ##TargetName##."
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin ##Infinitive::snarl##, `Back off!'",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::wrap## ##InitiatorPossessive## arms around ##TargetName##."
        ]),
    ]),
    "ignore": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::ignore####TargetName::the screams of the fallen##.",
        "can self-target": 1,
    ]),
    "insult": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::mutter## something slanderous about ##TargetName####TargetPreposition::and ##horses in physically improbable acts.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
        "can self-target": 1,
    ]),
    "jump": ([
        "template": "##InitiatorName## ##Infinitive::jump## ##Adverb::up and down####TargetPreposition::on####TargetName##.",
    ]),
    "kick": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::kick####TargetName::an invisible, deceased mime##.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -10,
        ]),
    ]),
    "kiss": ([
        "template": "##InitiatorName## ##Infinitive::kiss####TargetName::self## ##Adverb::affectionately##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::slap## ##TargetName## in the face and ##Infinitive::back## away.",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::wrap## ##InitiatorPossessive## arms around ##TargetName##."
        ]),
    ]),
    "laugh": ([
        "template": "##InitiatorName## ##Infinitive::fall## down ##Adverb## laughing##TargetPreposition::at####TargetName##.",
        "can self-target": 1,
    ]),
    "ld": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::get## clobbered by linkdeath - again and again.",
    ]),
    "lick": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::lick####TargetName::self##!",
        "reactions": ([
            "can be blocked": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::snarl##, `What the hell's wrong with you?'",
        ]),
    ]),
    "lol": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::laugh## out loud##TargetPreposition::at####TargetName##.",
    ]),
    "love": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::whisper## sweet words of love to##TargetName::the sky##.",
        "reactions": ([
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::reply## to ##TargetName##, `Sorry, I'm just not that in to you...'",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::wrap## ##InitiatorPossessive## arms around ##TargetName##."
        ]),
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
        "can self-target": 1,
        "reactions": ([
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::mutter##, `Asshole.'",
        ]),
    ]),
    "mstamp": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::slap## an official `I am a moron!' sticker on##TargetPossessive::Name::self## forehead.",
        "can self-target": 1,
        "reactions": ([
            "can be blocked": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the face and ##Infinitive::back## away.",
        ]),
    ]),
    "nibble": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nibble####TargetPossessive::Name::a dead rabbit's## ear.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::slap## ##TargetName## in the face and ##Infinitive::back## away.",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::kiss## ##TargetName##."
        ]),
    ]),
    "nod": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nod####TargetPreposition::at####TargetName##.",
    ]),
    "nog": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::nog####TargetPreposition::at####TargetName##.",
    ]),
    "noogie": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::give####TargetName::self## a noogie.",
        "reactions": ([
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::mutter##, `Asshole.'",
        ]),
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
        "reactions": ([
            "opinion modifier": -2,
        ]),
    ]),
    "peer": ([
        "template": "##InitiatorName## ##Infinitive::peer####TargetPreposition::at####TargetName::upward## ##Adverb::quizically##.",
    ]),
    "pfft": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::go## PFFT##TargetPreposition::at####TargetName##!",
    ]),
    "pinch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::pinch####TargetName::self##.",
        "can self-target": 1,
        "reactions": ([
            "opinion modifier": -2,
        ]),
    ]),
    "pizza": ([
        "template": "##InitiatorName## ##Infinitive::pizza####TargetPreposition::at####TargetName## ##Adverb::hungrily##.",
    ]),
    "please": ([
        "template": "##InitiatorName## ##Infinitive::make## puppy dog eyes##TargetPreposition::at####TargetName## and ##Adverb## ##Infinitive::say##, `Please?'",
    ]),
    "point": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::point####TargetPreposition::at####TargetName::upward##.",
        "can self-target": 1,
    ]),
    "poke": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetName::an invisible dragon## in the ribs.",
        "can self-target": 1,
        "reactions": ([
            "opinion modifier": -2,
        ]),
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
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::sidestep## the vomit and ##Infinitive::growls##, `Asshole.'",
        ]),
    ]),
    "punch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::punch####TargetName::at unseen foes##!",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the groin."
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::ruffle## ##TargetName## in the face with an elbow rather unplayfully.",
            "reciprocation": "##InitiatorName## ##Infinitive::smile## at ##TargetName##."
        ]),
    ]),
    "scratch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::scratch####TargetPossessive::Name::self## head.",
        "can self-target": 1,
    ]),
    "scream": ([
        "template": "##InitiatorName## ##Infinitive::scream## ##Adverb::loudly####TargetPreposition::at####TargetName##!",
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -1,
            "retaliation": "##InitiatorName## ##Infinitive::glare## at ##TargetName##.",
        ]),
    ]),
    "shake": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::shake####TargetPossessive::Name::self head####TargetPreposition::hand##.",
        "reactions": ([
            "can be blocked": 1,
            "opinion modifier": 2,
        ]),
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
        "can self-target": 1,
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the groin."
        ]),
    ]),
    "smile": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smile####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "smirk": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smirk####TargetPreposition::at####TargetName##.",
    ]),
    "smooch": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::smooch####TargetName::a passing harpy## with reckless abandon!",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::slap## ##TargetName## in the face and ##Infinitive::back## away.",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::kiss## ##TargetName##."
        ]),
    ]),
    "snap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::snap## ##InitiatorPossessive## fingers##TargetPreposition::at####TargetName##.",
    ]),
    "snarl": ([
        "template": "##InitiatorName## ##Infinitive::snarl## ##Adverb::angrily####TargetPreposition::at####TargetName##.",
        "reactions": ([
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::mutter##, `Asshole.'",
        ]),
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
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin ##Infinitive::snarl##, `Back off!'",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::wrap## ##InitiatorPossessive## arms around ##TargetName##."
        ]),
    ]),
    "sob": ([
        "template": "##InitiatorName## ##Infinitive::sob## ##Adverb::uncontrollably####TargetPreposition::to####TargetName##.",
    ]),
    "spank": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::spank####TargetName::self##!",
    ]),
    "spit": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::spit## on##TargetName::the ground##.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the groin."
        ]),
    ]),
    "squeeze": ([
        "template": "##InitiatorName## ##Infinitive::squeeze####TargetName::self## ##Adverb::fondly##.",
        "reactions": ([
            "can be blocked": 1,
            "romance action": 1,
            "opinion modifier": 5,
            "retaliation": "##InitiatorName## ##Infinitive::knee## ##TargetName## in the groin ##Infinitive::snarl##, `Back off!'",
            "reciprocation": "##InitiatorName## tenderly ##Infinitive::wrap## ##InitiatorPossessive## arms around ##TargetName##."
        ]),
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
        "can self-target": 1,
        "reactions": ([
            "hostile action": 1,
            "opinion modifier": -5,
        ]),
    ]),
    "tease": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::tease####TargetName::cabbage for, well, being cabbage##.",
        "can self-target": 1,
        "reactions": ([
            "opinion modifier": -1,
        ]),
    ]),
    "thank": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::thank####TargetName::the world for every dead mime##.",
        "can self-target": 1,
        "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "think": ([
        "template": "##InitiatorName## ##Infinitive::think####TargetPreposition::about####TargetName## ##Adverb::carefully##.",
        "can self-target": 1,
    ]),
    "thwap": ([
        "template": "##InitiatorName## ##Adverb## ##Infinitive::thwap####TargetName::self##.",
        "reactions": ([
            "can be blocked": 1,
            "hostile action": 1,
            "opinion modifier": -5,
            "retaliation": "##InitiatorName## ##Infinitive::punch## ##TargetName## in the nose."
        ]),
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
        "reactions": ([
            "opinion modifier": 1,
        ]),
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
        "reactions": ([
            "opinion modifier": 1,
        ]),
    ]),
    "worship": ([
        "template": "##InitiatorName## ##Infinitive::fall## to the ground and ##Adverb## ##Infinitive::worship####TargetName::a dust bunny##.",
        "reactions": ([
            "opinion modifier": 1,
        ]),
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
        "reactions": ([
            "opinion modifier": -2,
        ]),
    ]),
    "zing": ([
        "template": "##InitiatorName## ##Infinitive::hold## up a finger and ##Adverb## ##Infinitive::say##, `Zing!'",
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
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

/////////////////////////////////////////////////////////////////////////////
private nomask void speakMessage(string messageTemplate,
    object initiator, object target)
{
    if (environment(initiator))
    {
        object configuration = load_object("/lib/dictionaries/configurationDictionary.c");
        if (objectp(target) && target->blocked(initiator))
        {
            tell_object(initiator, configuration->decorate(
                format(sprintf("Command failed: You have been blocked "
                    "by %s and cannot target %s.\n",
                    capitalize(target->RealName()), target->Objective()), 78),
                "block", "soul", initiator->colorConfiguration()));
        }
        else
        {
            object *characters = filter(all_inventory(environment(initiator)),
                (: $1->isRealizationOfLiving() :));

            foreach(object person in characters)
            {
                if (person && objectp(person))
                {
                    string parsedMessage = messageTemplate;

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

                    if (!person->blocked(initiator))
                    {
                        tell_object(person, configuration->decorate(
                            format(parsedMessage, 78), "message", "soul",
                            person->colorConfiguration()));
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string removeTargetString(string messageTemplate)
{
    string ret = regreplace(messageTemplate, "##TargetName::self##", " ##InitiatorReflexive##", 1);
    ret = regreplace(ret, "##TargetName::([^#]+)*##", " \\1", 1);
    ret = regreplace(ret, "##TargetPossessive::Name::self([^#]+)*##", " ##InitiatorPossessive##\\1", 1);
    ret = regreplace(ret, "##TargetPossessive::Name::([^#]+)*##", " \\1", 1);
    ret = regreplace(ret, "##TargetPreposition::[^#]+##", "", 1);
    ret = regreplace(ret, "##Target[^#]+##", "");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string replaceTargetDetails(string messageTemplate, string target,
    object targetObj)
{
    string ret = regreplace(messageTemplate, "([^ \"])##Target", "\\1 ##Target", 1);
    ret = regreplace(ret, "##TargetName(::[^#]+)*##", "##TargetName##", 1);
    ret = regreplace(ret, "##TargetPossessive::Name(::[^#]+)*##", "##TargetPossessive::Name##", 1);
    if (!targetObj)
    {
        ret = regreplace(ret, "##TargetName##", target);
    }
    ret = regreplace(ret, "##TargetPreposition::([^#]+)##", "\\1", 1);
    ret = regreplace(ret, " ([,;.!?] )", "\\1", 1);
    return ret;
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

                messageTemplate = replaceTargetDetails(messageTemplate, target, targetObj);
            }
            else
            {
                messageTemplate = removeTargetString(messageTemplate);
            }

            // This will kill the other flags
            string commandList = "(" + implode(m_indices(emoteTemplates), "|") + ")";
            if (sizeof(regexp(({ action + command }), commandList + " -[A-Za-z]+")))
            {
                string flag = regreplace(action + command, commandList + " (-[A-Za-z]+).*", "\\2", 1);
                tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
            }
            else if ((initiator == targetObj) && !member(emoteTemplates[action], "can self-target"))
            {
                tell_object(initiator, "Command failed: You cannot target yourself.\n");
            }
            else
            {
                speakMessage(messageTemplate, initiator, targetObj);

                if (targetObj && (initiator != targetObj) && 
                    !targetObj->isRealizationOfPlayer() &&
                    member(emoteTemplates[action], "reactions"))
                {
                    if (member(emoteTemplates[action]["reactions"], "retaliation"))
                    {
                        speakMessage(emoteTemplates[action]["reactions"]["retaliation"],
                            targetObj, initiator);
                    }
                    if (member(emoteTemplates[action], "opinion modifier"))
                    {
                        targetObj->alterOpinionFromEmote(initiator,
                            emoteTemplates[action]);
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string usageDetails(string displayCommand, string colorConfiguration)
{
    string ret = "";

    string *command = filter(commands,
        (: sizeof(regexp(({ $1 }), "^" + displayCommand + " ")) :));

    if (sizeof(command) && member(emoteTemplates, displayCommand))
    {
        string *commandText = ({});
        foreach(string commandItem in command)
        {
            string currentCommand = regreplace(commandItem, "\\[\\.\\*\\]",
                wildcardMeaning(colorConfiguration), 1);

            currentCommand = regreplace(currentCommand, "[[][(]([^|]+)[|]([^]]+)[)][+]", "[\\1] [\\2", 1);
            currentCommand = format(regreplace(currentCommand, "\\|", "", 1), 78);
            currentCommand = regreplace(currentCommand, "([^#]*)##([^#]+)##([^#]*)",
                configuration->decorate("\\1", "text", "help", colorConfiguration) +
                configuration->decorate("<\\2>", "parameter", "help", colorConfiguration) +
                configuration->decorate("\\3", "text", "help", colorConfiguration), 1);
            if (!sizeof(regexp(({ currentCommand }), "\x1b")))
            {
                currentCommand = configuration->decorate(currentCommand,
                    "text", "help", colorConfiguration);
            }
            commandText += ({ regreplace(currentCommand, "\n", "\n\t\t", 1) });
        }
        ret = "\t" + implode(commandText, "\n\t") + "\n";
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Execute a soul command";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-*[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-a":
        {
            ret = "This option will add or replace the soul command's adverb "
                "with the supplied value. For example:\n> laugh -a raucously\n"
                "You laugh raucously.";
            break;
        }
        case "-t":
        {
            ret = "This option will target the supplied character with the "
                "soul command. For example:\n> laugh -t earl\nYou laugh "
                "at Earl.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The various soul commands are a series of canned emotes "
        "that can be used to interact with other players and characters "
        "in the game. For non-player characters, many of these commands "
        "will have an affect on their opinion of the player and can "
        "lead to reciprocation, be it friendly, rude, or romantic. Much of "
        "these reciprocations are directly tied to the character's "
        "personality traits. If you abuse an NPC, don't be surprised if "
        "they abuse you back!\n\nPlayers can block other players from "
        "using these commands against them via the 'block player' setting. "
        "that can be modified via the set command.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: soul, emote, and set";
}
