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
    "goose": "##InitiatorName## ##Adverb## ##Infinitive::goose####TargetPreposition::at####TargetName##.",
    "grab": "##InitiatorName## ##Adverb## ##Infinitive::grab####TargetPreposition::at####TargetName##.",
    "grimace": "##InitiatorName## ##Adverb## ##Infinitive::grimace####TargetPreposition::at####TargetName##.",
    "grin": "##InitiatorName## ##Adverb## ##Infinitive::grin####TargetPreposition::at####TargetName##.",
    "groan": "##InitiatorName## ##Adverb## ##Infinitive::groan####TargetPreposition::at####TargetName##.",
    "grope": "##InitiatorName## ##Adverb## ##Infinitive::grope####TargetPreposition::at####TargetName##.",
    "grovel": "##InitiatorName## ##Adverb## ##Infinitive::grovel####TargetPreposition::at####TargetName##.",
    "growl": "##InitiatorName## ##Adverb## ##Infinitive::growl####TargetPreposition::at####TargetName##.",
    "grumble": "##InitiatorName## ##Adverb## ##Infinitive::grumble####TargetPreposition::at####TargetName##.",
    "guffaw": "##InitiatorName## ##Adverb## ##Infinitive::guffaw####TargetPreposition::at####TargetName##.",
    "hair": "##InitiatorName## ##Adverb## ##Infinitive::hair####TargetPreposition::at####TargetName##.",
    "handkiss": "##InitiatorName## ##Adverb## ##Infinitive::handkiss####TargetPreposition::at####TargetName##.",
    "harumph": "##InitiatorName## ##Adverb## ##Infinitive::harumph####TargetPreposition::at####TargetName##.",
    "hee": "##InitiatorName## ##Adverb## ##Infinitive::hee####TargetPreposition::at####TargetName##.",
    "heh": "##InitiatorName## ##Adverb## ##Infinitive::heh####TargetPreposition::at####TargetName##.",
    "hi5": "##InitiatorName## ##Adverb## ##Infinitive::hi5####TargetPreposition::at####TargetName##.",
    "hiccup": "##InitiatorName## ##Adverb## ##Infinitive::hiccup####TargetPreposition::at####TargetName##.",
    "hmm": "##InitiatorName## ##Adverb## ##Infinitive::hmm####TargetPreposition::at####TargetName##.",
    "hold": "##InitiatorName## ##Adverb## ##Infinitive::hold####TargetPreposition::at####TargetName##.",
    "hop": "##InitiatorName## ##Adverb## ##Infinitive::hop####TargetPreposition::at####TargetName##.",
    "howl": "##InitiatorName## ##Adverb## ##Infinitive::howl####TargetPreposition::at####TargetName##.",
    "hrm": "##InitiatorName## ##Adverb## ##Infinitive::hrm####TargetPreposition::at####TargetName##.",
    "hug": "##InitiatorName## ##Adverb## ##Infinitive::hug####TargetPreposition::at####TargetName##.",
    "huggle": "##InitiatorName## ##Adverb## ##Infinitive::huggle####TargetPreposition::at####TargetName##.",
    "ignore": "##InitiatorName## ##Adverb## ##Infinitive::ignore####TargetPreposition::at####TargetName##.",
    "insult": "##InitiatorName## ##Adverb## ##Infinitive::insult####TargetPreposition::at####TargetName##.",
    "jump": "##InitiatorName## ##Adverb## ##Infinitive::jump####TargetPreposition::at####TargetName##.",
    "kick": "##InitiatorName## ##Adverb## ##Infinitive::kick####TargetPreposition::at####TargetName##.",
    "kiss": "##InitiatorName## ##Adverb## ##Infinitive::kiss####TargetPreposition::at####TargetName##.",
    "laugh": "##InitiatorName## ##Adverb## ##Infinitive::laugh####TargetPreposition::at####TargetName##.",
    "ld": "##InitiatorName## ##Adverb## ##Infinitive::ld####TargetPreposition::at####TargetName##.",
    "lick": "##InitiatorName## ##Adverb## ##Infinitive::lick####TargetPreposition::at####TargetName##.",
    "lol": "##InitiatorName## ##Adverb## ##Infinitive::lol####TargetPreposition::at####TargetName##.",
    "love": "##InitiatorName## ##Adverb## ##Infinitive::love####TargetPreposition::at####TargetName##.",
    "meh": "##InitiatorName## ##Adverb## ##Infinitive::meh####TargetPreposition::at####TargetName##.",
    "mgrin": "##InitiatorName## ##Adverb## ##Infinitive::mgrin####TargetPreposition::at####TargetName##.",
    "moan": "##InitiatorName## ##Adverb## ##Infinitive::moan####TargetPreposition::at####TargetName##.",
    "mock": "##InitiatorName## ##Adverb## ##Infinitive::mock####TargetPreposition::at####TargetName##.",
    "mstamp": "##InitiatorName## ##Adverb## ##Infinitive::mstamp####TargetPreposition::at####TargetName##.",
    "muffle": "##InitiatorName## ##Adverb## ##Infinitive::muffle####TargetPreposition::at####TargetName##.",
    "nibble": "##InitiatorName## ##Adverb## ##Infinitive::nibble####TargetPreposition::at####TargetName##.",
    "nod": "##InitiatorName## ##Adverb## ##Infinitive::nod####TargetPreposition::at####TargetName##.",
    "nog": "##InitiatorName## ##Adverb## ##Infinitive::nog####TargetPreposition::at####TargetName##.",
    "noogie": "##InitiatorName## ##Adverb## ##Infinitive::noogie####TargetPreposition::at####TargetName##.",
    "nudge": "##InitiatorName## ##Adverb## ##Infinitive::nudge####TargetPreposition::at####TargetName##.",
    "nurse": "##InitiatorName## ##Adverb## ##Infinitive::nurse####TargetPreposition::at####TargetName##.",
    "nuzzle": "##InitiatorName## ##Adverb## ##Infinitive::nuzzle####TargetPreposition::at####TargetName##.",
    "ouch": "##InitiatorName## ##Adverb## ##Infinitive::ouch####TargetPreposition::at####TargetName##.",
    "pace": "##InitiatorName## ##Adverb## ##Infinitive::pace####TargetPreposition::at####TargetName##.",
    "panic": "##InitiatorName## ##Adverb## ##Infinitive::panic####TargetPreposition::at####TargetName##.",
    "pat": "##InitiatorName## ##Adverb## ##Infinitive::pat####TargetPreposition::at####TargetName##.",
    "peer": "##InitiatorName## ##Adverb## ##Infinitive::peer####TargetPreposition::at####TargetName##.",
    "pfft": "##InitiatorName## ##Adverb## ##Infinitive::pfft####TargetPreposition::at####TargetName##.",
    "pinch": "##InitiatorName## ##Adverb## ##Infinitive::pinch####TargetPreposition::at####TargetName##.",
    "pizza": "##InitiatorName## ##Adverb## ##Infinitive::pizza####TargetPreposition::at####TargetName##.",
    "please": "##InitiatorName## ##Adverb## ##Infinitive::please####TargetPreposition::at####TargetName##.",
    "point": "##InitiatorName## ##Adverb## ##Infinitive::point####TargetPreposition::at####TargetName##.",
    "poke": "##InitiatorName## ##Adverb## ##Infinitive::poke####TargetPreposition::at####TargetName##.",
    "ponder": "##InitiatorName## ##Adverb## ##Infinitive::ponder####TargetPreposition::at####TargetName##.",
    "pounce": "##InitiatorName## ##Adverb## ##Infinitive::pounce####TargetPreposition::at####TargetName##.",
    "pout": "##InitiatorName## ##Adverb## ##Infinitive::pout####TargetPreposition::at####TargetName##.",
    "puke": "##InitiatorName## ##Adverb## ##Infinitive::puke####TargetPreposition::at####TargetName##.",
    "punch": "##InitiatorName## ##Adverb## ##Infinitive::punch####TargetPreposition::at####TargetName##.",
    "purr": "##InitiatorName## ##Adverb## ##Infinitive::purr####TargetPreposition::at####TargetName##.",
    "puzzle": "##InitiatorName## ##Adverb## ##Infinitive::puzzle####TargetPreposition::at####TargetName##.",
    "raise": "##InitiatorName## ##Adverb## ##Infinitive::raise####TargetPreposition::at####TargetName##.",
    "rdance": "##InitiatorName## ##Adverb## ##Infinitive::rdance####TargetPreposition::at####TargetName##.",
    "recoil": "##InitiatorName## ##Adverb## ##Infinitive::recoil####TargetPreposition::at####TargetName##.",
    "rofl": "##InitiatorName## ##Adverb## ##Infinitive::rofl####TargetPreposition::at####TargetName##.",
    "roll": "##InitiatorName## ##Adverb## ##Infinitive::roll####TargetPreposition::at####TargetName##.",
    "ruffle": "##InitiatorName## ##Adverb## ##Infinitive::ruffle####TargetPreposition::at####TargetName##.",
    "scratch": "##InitiatorName## ##Adverb## ##Infinitive::scratch####TargetPreposition::at####TargetName##.",
    "scream": "##InitiatorName## ##Adverb## ##Infinitive::scream####TargetPreposition::at####TargetName##.",
    "shake": "##InitiatorName## ##Adverb## ##Infinitive::shake####TargetPreposition::at####TargetName##.",
    "shh": "##InitiatorName## ##Adverb## ##Infinitive::shh####TargetPreposition::at####TargetName##.",
    "shiver": "##InitiatorName## ##Adverb## ##Infinitive::shiver####TargetPreposition::at####TargetName##.",
    "shivers": "##InitiatorName## ##Adverb## ##Infinitive::shivers####TargetPreposition::at####TargetName##.",
    "shrug": "##InitiatorName## ##Adverb## ##Infinitive::shrug####TargetPreposition::at####TargetName##.",
    "shudder": "##InitiatorName## ##Adverb## ##Infinitive::shudder####TargetPreposition::at####TargetName##.",
    "sigh": "##InitiatorName## ##Adverb## ##Infinitive::sigh####TargetPreposition::at####TargetName##.",
    "sing": "##InitiatorName## ##Adverb## ##Infinitive::sing####TargetPreposition::at####TargetName##.",
    "slap": "##InitiatorName## ##Adverb## ##Infinitive::slap####TargetPreposition::at####TargetName##.",
    "smile": "##InitiatorName## ##Adverb## ##Infinitive::smile####TargetPreposition::at####TargetName##.",
    "smirk": "##InitiatorName## ##Adverb## ##Infinitive::smirk####TargetPreposition::at####TargetName##.",
    "smooch": "##InitiatorName## ##Adverb## ##Infinitive::smooch####TargetPreposition::at####TargetName##.",
    "snap": "##InitiatorName## ##Adverb## ##Infinitive::snap####TargetPreposition::at####TargetName##.",
    "snarl": "##InitiatorName## ##Adverb## ##Infinitive::snarl####TargetPreposition::at####TargetName##.",
    "sneeze": "##InitiatorName## ##Adverb## ##Infinitive::sneeze####TargetPreposition::at####TargetName##.",
    "snicker": "##InitiatorName## ##Adverb## ##Infinitive::snicker####TargetPreposition::at####TargetName##.",
    "sniff": "##InitiatorName## ##Adverb## ##Infinitive::sniff####TargetPreposition::at####TargetName##.",
    "snore": "##InitiatorName## ##Adverb## ##Infinitive::snore####TargetPreposition::at####TargetName##.",
    "snort": "##InitiatorName## ##Adverb## ##Infinitive::snort####TargetPreposition::at####TargetName##.",
    "snuggle": "##InitiatorName## ##Adverb## ##Infinitive::snuggle####TargetPreposition::at####TargetName##.",
    "sob": "##InitiatorName## ##Adverb## ##Infinitive::sob####TargetPreposition::at####TargetName##.",
    "spank": "##InitiatorName## ##Adverb## ##Infinitive::spank####TargetPreposition::at####TargetName##.",
    "spit": "##InitiatorName## ##Adverb## ##Infinitive::spit####TargetPreposition::at####TargetName##.",
    "squeeze": "##InitiatorName## ##Adverb## ##Infinitive::squeeze####TargetPreposition::at####TargetName##.",
    "squirm": "##InitiatorName## ##Adverb## ##Infinitive::squirm####TargetPreposition::at####TargetName##.",
    "stare": "##InitiatorName## ##Adverb## ##Infinitive::stare####TargetPreposition::at####TargetName##.",
    "start": "##InitiatorName## ##Adverb## ##Infinitive::start####TargetPreposition::at####TargetName##.",
    "steam": "##InitiatorName## ##Adverb## ##Infinitive::steam####TargetPreposition::at####TargetName##.",
    "stomp": "##InitiatorName## ##Adverb## ##Infinitive::stomp####TargetPreposition::at####TargetName##.",
    "stretch": "##InitiatorName## ##Adverb## ##Infinitive::stretch####TargetPreposition::at####TargetName##.",
    "strut": "##InitiatorName## ##Adverb## ##Infinitive::strut####TargetPreposition::at####TargetName##.",
    "sulk": "##InitiatorName## ##Adverb## ##Infinitive::sulk####TargetPreposition::at####TargetName##.",
    "swim": "##InitiatorName## ##Adverb## ##Infinitive::swim####TargetPreposition::at####TargetName##.",
    "tackle": "##InitiatorName## ##Adverb## ##Infinitive::tackle####TargetPreposition::at####TargetName##.",
    "tahdah": "##InitiatorName## ##Adverb## ##Infinitive::tahdah####TargetPreposition::at####TargetName##.",
    "tap": "##InitiatorName## ##Adverb## ##Infinitive::tap####TargetPreposition::at####TargetName##.",
    "taunt": "##InitiatorName## ##Adverb## ##Infinitive::taunt####TargetPreposition::at####TargetName##.",
    "tease": "##InitiatorName## ##Adverb## ##Infinitive::tease####TargetPreposition::at####TargetName##.",
    "thank": "##InitiatorName## ##Adverb## ##Infinitive::thank####TargetPreposition::at####TargetName##.",
    "think": "##InitiatorName## ##Adverb## ##Infinitive::think####TargetPreposition::at####TargetName##.",
    "thwap": "##InitiatorName## ##Adverb## ##Infinitive::thwap####TargetPreposition::at####TargetName##.",
    "tickle": "##InitiatorName## ##Adverb## ##Infinitive::tickle####TargetPreposition::at####TargetName##.",
    "tsk": "##InitiatorName## ##Adverb## ##Infinitive::tsk####TargetPreposition::at####TargetName##.",
    "twiddle": "##InitiatorName## ##Adverb## ##Infinitive::twiddle####TargetPreposition::at####TargetName##.",
    "twitch": "##InitiatorName## ##Adverb## ##Infinitive::twitch####TargetPreposition::at####TargetName##.",
    "wave": "##InitiatorName## ##Adverb## ##Infinitive::wave####TargetPreposition::at####TargetName##.",
    "wedgie": "##InitiatorName## ##Adverb## ##Infinitive::wedgie####TargetPreposition::at####TargetName##.",
    "weenie": "##InitiatorName## ##Adverb## ##Infinitive::weenie####TargetPreposition::at####TargetName##.",
    "weird": "##InitiatorName## ##Adverb## ##Infinitive::weird####TargetPreposition::at####TargetName##.",
    "well": "##InitiatorName## ##Adverb## ##Infinitive::well####TargetPreposition::at####TargetName##.",
    "whee": "##InitiatorName## ##Adverb## ##Infinitive::whee####TargetPreposition::at####TargetName##.",
    "whine": "##InitiatorName## ##Adverb## ##Infinitive::whine####TargetPreposition::at####TargetName##.",
    "whistle": "##InitiatorName## ##Adverb## ##Infinitive::whistle####TargetPreposition::at####TargetName##.",
    "wiggle": "##InitiatorName## ##Adverb## ##Infinitive::wiggle####TargetPreposition::at####TargetName##.",
    "wink": "##InitiatorName## ##Adverb## ##Infinitive::wink####TargetPreposition::at####TargetName##.",
    "worship": "##InitiatorName## ##Adverb## ##Infinitive::worship####TargetPreposition::at####TargetName##.",
    "yawn": "##InitiatorName## ##Adverb## ##Infinitive::yawn####TargetPreposition::at####TargetName##.",
    "yay": "##InitiatorName## ##Adverb## ##Infinitive::yay####TargetPreposition::at####TargetName##.",
    "yeah": "##InitiatorName## ##Adverb## ##Infinitive::yeah####TargetPreposition::at####TargetName##.",
    "yodel": "##InitiatorName## ##Adverb## ##Infinitive::yodel####TargetPreposition::at####TargetName##.",
    "yuck": "##InitiatorName## ##Adverb## ##Infinitive::yuck####TargetPreposition::at####TargetName##.",
    "zing": "##InitiatorName## ##Adverb## ##Infinitive::zing####TargetPreposition::at####TargetName##.",
]);

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
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
                messageTemplate = regreplace(messageTemplate, "##TargetPossessive::Name::([^#]+)*##", " \\1", 1);
                messageTemplate = regreplace(messageTemplate, "##TargetPreposition::[^#]+##", "", 1);
                messageTemplate = regreplace(messageTemplate, "##Target[^#]+##", "");
            }

            // This will kill the other flags
            string commandList = "(" + implode(m_indices(emoteTemplates), "|") + ")";
            if (sizeof(regexp(({ command }), commandList + " -[A-Za-z]+")))
            {
                string flag = regreplace(command, commandList + " (-[A-Za-z]+).*", "\\2", 1);
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
