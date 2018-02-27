//*****************************************************************************
// Copyright (c) 2018 -Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Target;
object Bystander;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Race("human");
    Player->Gender(1);
    Player->addCommands();
    move_object(Player, this_object());

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->Gender(1);
    Target->addCommands();
    move_object(Target, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->addCommands();
    move_object(Bystander, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Target);
    destruct(Bystander);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidFlagsDoNotParse()
{
    ExpectTrue(Player->executeCommand("ack -ve blah"));
    ExpectEq("Command failed: The '-ve' flag is not valid.\n",
        Player->caughtMessage());

    ExpectTrue(Player->executeCommand("admire -adverbiage blah Hi!"));
    ExpectEq("Command failed: The '-adverbiage' flag is not valid.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AckWithoutFlagsDisplaysCorrectMessage()
{
    ExpectTrue(Player->executeCommand("ack"));

    ExpectEq("You ack.\n", Player->caughtMessage());
    ExpectEq("Bob acks.\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AckWithFlagsDisplaysCorrectMessage()
{
    ExpectTrue(Player->executeCommand("ack -t bob"));
    ExpectEq("You ack at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob acks at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ack -a stupidly -t earl"));
    ExpectEq("You stupidly ack at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob stupidly acks at you.\n", Target->caughtMessage());
    ExpectEq("Bob stupidly acks at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AdmireDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("admire"));
    ExpectEq("You admire the ambiguity of admiring without a target.\n", Player->caughtMessage());
    ExpectEq("Bob admires the ambiguity of admiring without a target.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("admire -t bob"));
    ExpectEq("You admire Bob.\n", Player->caughtMessage());
    ExpectEq("Bob admires Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("admire -a inexplicably -t earl"));
    ExpectEq("You inexplicably admire Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably admires you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably admires Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AgreeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("agree"));
    ExpectEq("You agree.\n", Player->caughtMessage());
    ExpectEq("Bob agrees.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("agree -t bob"));
    ExpectEq("You agree with Bob.\n", Player->caughtMessage());
    ExpectEq("Bob agrees with Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("agree -a inexplicably -t earl"));
    ExpectEq("You inexplicably agree with Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably agrees with you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably agrees with Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AgrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("agrin"));
    ExpectEq("You grin like an ass.\n", Player->caughtMessage());
    ExpectEq("Bob grins like an ass.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("agrin -t bob"));
    ExpectEq("You grin at Bob like an ass.\n", Player->caughtMessage());
    ExpectEq("Bob grins at Bob like an ass.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("agrin -a inexplicably -t earl"));
    ExpectEq("You inexplicably grin at Earl like an ass.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably grins at you like an ass.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably grins at Earl like an ass.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AhaDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("aha"));
    ExpectEq("You go 'Aha!'.\n", Player->caughtMessage());
    ExpectEq("Bob goes 'Aha!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("aha -t bob"));
    ExpectEq("You go 'Aha!' at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob goes 'Aha!' at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("aha -a inexplicably -t earl"));
    ExpectEq("You inexplicably go 'Aha!' at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably goes 'Aha!' at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably goes 'Aha!' at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AhhDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ahh"));
    ExpectEq("You go AHHH.\n", Player->caughtMessage());
    ExpectEq("Bob goes AHHH.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ahh -t bob"));
    ExpectEq("You go AHHH at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob goes AHHH at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ahh -a inexplicably -t earl"));
    ExpectEq("You inexplicably go AHHH at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably goes AHHH at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably goes AHHH at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AmorousDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("amorous"));
    ExpectEq("You feel amorous.\n", Player->caughtMessage());
    ExpectEq("Bob feels amorous.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("amorous -t bob"));
    ExpectEq("You feel amorous toward Bob.\n", Player->caughtMessage());
    ExpectEq("Bob feels amorous toward Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("amorous -a inexplicably -t earl"));
    ExpectEq("You inexplicably feel amorous toward Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably feels amorous toward you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably feels amorous toward Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AnnoyDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("annoy"));
    ExpectEq("You are annoying.\n", Player->caughtMessage());
    ExpectEq("Bob is annoying.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("annoy -t bob"));
    ExpectEq("You are annoying Bob.\n", Player->caughtMessage());
    ExpectEq("Bob is annoying Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("annoy -a inexplicably -t earl"));
    ExpectEq("You are inexplicably annoying Earl.\n", Player->caughtMessage());
    ExpectEq("Bob is inexplicably annoying you.\n", Target->caughtMessage());
    ExpectEq("Bob is inexplicably annoying Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ApologizeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("apologize"));
    ExpectEq("You apologize.\n", Player->caughtMessage());
    ExpectEq("Bob apologizes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("apologize -t bob"));
    ExpectEq("You apologize to Bob.\n", Player->caughtMessage());
    ExpectEq("Bob apologizes to Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("apologize -a inexplicably -t earl"));
    ExpectEq("You inexplicably apologize to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably apologizes to you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably apologizes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ApplaudDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("applaud"));
    ExpectEq("You give a round of applause.\n", Player->caughtMessage());
    ExpectEq("Bob gives a round of applause.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("applaud -t bob"));
    ExpectEq("You give a round of applause to Bob.\n", Player->caughtMessage());
    ExpectEq("Bob gives a round of applause to Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("applaud -a inexplicably -t earl"));
    ExpectEq("You inexplicably give a round of applause to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably gives a round of applause to you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably gives a round of applause to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AytDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ayt"));
    ExpectEq("You wave your hand back and forth and say, 'Are you there?'\n", Player->caughtMessage());
    ExpectEq("Bob waves his hand back and forth and says, 'Are you there?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ayt -t bob"));
    ExpectEq("You wave your hand back and forth in front of Bob and say, 'Are you there?'\n", Player->caughtMessage());
    ExpectEq("Bob waves his hand back and forth in front of Bob and says, 'Are you there?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ayt -a inexplicably -t earl"));
    ExpectEq("You inexplicably wave your hand back and forth in front of Earl and say, 'Are\nyou there?'\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably waves his hand back and forth in front of you and says, 'Are\nyou there?'\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably waves his hand back and forth in front of Earl and says, 'Are\nyou there?'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BackhandDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("backhand"));
    ExpectEq("You backhand an invisible, deceased llama.\n", Player->caughtMessage());
    ExpectEq("Bob backhands an invisible, deceased llama.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("backhand -t bob"));
    ExpectEq("You backhand Bob.\n", Player->caughtMessage());
    ExpectEq("Bob backhands Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("backhand -a inexplicably -t earl"));
    ExpectEq("You inexplicably backhand Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably backhands you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably backhands Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BahaDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("baha"));
    ExpectEq("You go BAHAHAHA.\n", Player->caughtMessage());
    ExpectEq("Bob goes BAHAHAHA.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("baha -t bob"));
    ExpectEq("You go BAHAHAHA at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob goes BAHAHAHA at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("baha -a inexplicably -t earl"));
    ExpectEq("You inexplicably go BAHAHAHA at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably goes BAHAHAHA at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably goes BAHAHAHA at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BarkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bark"));
    ExpectEq("You bark like a dog.\n", Player->caughtMessage());
    ExpectEq("Bob barks like a dog.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bark -t bob"));
    ExpectEq("You bark like a dog at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob barks like a dog at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bark -a inexplicably -t earl"));
    ExpectEq("You inexplicably bark like a dog at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably barks like a dog at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably barks like a dog at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BreakdanceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("breakdance"));
    ExpectEq("You breakdance like a madman.\n", Player->caughtMessage());
    ExpectEq("Bob breakdances like a madman.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("breakdance -t bob"));
    ExpectEq("You breakdance like a madman around Bob.\n", Player->caughtMessage());
    ExpectEq("Bob breakdances like a madman around Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("breakdance -a inexplicably -t earl"));
    ExpectEq("You inexplicably breakdance like a madman around Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably breakdances like a madman around you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably breakdances like a madman around Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BeamDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("beam"));
    ExpectEq("You beam like a lightbulb.\n", Player->caughtMessage());
    ExpectEq("Bob beams like a lightbulb.\n", Target->caughtMessage());

    // This proves that the emote is not targetted and -t is ignored.
    ExpectTrue(Player->executeCommand("beam -a inexplicably -t earl"));
    ExpectEq("You inexplicably beam like a lightbulb.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably beams like a lightbulb.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably beams like a lightbulb.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BeepDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("beep"));
    ExpectEq("You beep like a person mercilessly spared from the ravages of sanity.\n", Player->caughtMessage());
    ExpectEq("Bob beeps like a person mercilessly spared from the ravages of sanity.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("beep -t bob"));
    ExpectEq("You beep Bob on the nose.\n", Player->caughtMessage());
    ExpectEq("Bob beeps Bob on the nose.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("beep -a viciously -t earl"));
    ExpectEq("You viciously beep Earl on the nose.\n", Player->caughtMessage());
    ExpectEq("Bob viciously beeps you on the nose.\n", Target->caughtMessage());
    ExpectEq("Bob viciously beeps Earl on the nose.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BegDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("beg"));
    ExpectEq("You beg like a dog.\n", Player->caughtMessage());
    ExpectEq("Bob begs like a dog.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("beg -t bob"));
    ExpectEq("You beg like a dog at Bob.\n", Player->caughtMessage());
    ExpectEq("Bob begs like a dog at Bob.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("beg -a inexplicably -t earl"));
    ExpectEq("You inexplicably beg like a dog at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably begs like a dog at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably begs like a dog at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BleedDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bleed"));
    ExpectEq("You bleed.\n", Player->caughtMessage());
    ExpectEq("Bob bleeds.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bleed -a inexplicably -t earl"));
    ExpectEq("You inexplicably bleed.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably bleeds.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably bleeds.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlinkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("blink"));
    ExpectEq("You blink.\n", Player->caughtMessage());
    ExpectEq("Bob blinks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("blink -a inexplicably -t earl"));
    ExpectEq("You inexplicably blink at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably blinks at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably blinks at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlushDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("blush"));
    ExpectEq("You blush.\n", Player->caughtMessage());
    ExpectEq("Bob blushes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("blush -a inexplicably -t earl"));
    ExpectEq("You inexplicably blush while looking at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably blushes while looking at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably blushes while looking at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BoggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("boggle"));
    ExpectEq("You boggle at the concept.\n", Player->caughtMessage());
    ExpectEq("Bob boggles at the concept.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("boggle -a inexplicably -t earl"));
    ExpectEq("You inexplicably boggle at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably boggles at you.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably boggles at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BooDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("boo"));
    ExpectEq("You snarl BOO! HISS!\n", Player->caughtMessage());
    ExpectEq("Bob snarls BOO! HISS!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("boo -t bob"));
    ExpectEq("You snarl behind Bob scaring the $%!@ out of him!\n", Player->caughtMessage());
    ExpectEq("Bob snarls behind Bob scaring the $%!@ out of him!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("boo -a sneakily -t earl"));
    ExpectEq("You sneakily snarl behind Earl scaring the $%!@ out of him!\n", Player->caughtMessage());
    ExpectEq("Bob sneakily snarls behind you scaring the $%!@ out of you!\n", Target->caughtMessage());
    ExpectEq("Bob sneakily snarls behind Earl scaring the $%!@ out of him!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BootDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("boot"));
    ExpectEq("You give an imaginary mime a boot to the head!\n", Player->caughtMessage());
    ExpectEq("Bob gives an imaginary mime a boot to the head!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("boot -a inexplicably -t earl"));
    ExpectEq("You inexplicably give Earl a boot to the head!\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably gives you a boot to the head!\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably gives Earl a boot to the head!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BootieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bootie"));
    ExpectEq("You shake your bootie!\n", Player->caughtMessage());
    ExpectEq("Bob shakes his bootie!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bootie -a inexplicably -t earl"));
    ExpectEq("You inexplicably shake your bootie!\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably shakes his bootie!\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably shakes his bootie!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BopDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bop"));
    ExpectEq("You bop an invisible flying turtle!\n", Player->caughtMessage());
    ExpectEq("Bob bops an invisible flying turtle!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bop -a inexplicably -t earl"));
    ExpectEq("You inexplicably bop Earl!\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably bops you!\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably bops Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BoredDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bored"));
    ExpectEq("You are bored.\n", Player->caughtMessage());
    ExpectEq("Bob is bored.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bored -a inexplicably -t earl"));
    ExpectEq("You are inexplicably bored with Earl.\n", Player->caughtMessage());
    ExpectEq("Bob is inexplicably bored with you.\n", Target->caughtMessage());
    ExpectEq("Bob is inexplicably bored with Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BounceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bounce"));
    ExpectEq("You bounce up and down.\n", Player->caughtMessage());
    ExpectEq("Bob bounces up and down.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bounce -a inexplicably -t earl"));
    ExpectEq("You inexplicably bounce up and down.\n", Player->caughtMessage());
    ExpectEq("Bob inexplicably bounces up and down.\n", Target->caughtMessage());
    ExpectEq("Bob inexplicably bounces up and down.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BowDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bow"));
    ExpectEq("You bow gracefully.\n", Player->caughtMessage());
    ExpectEq("Bob bows gracefully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bow -a ineptly -t earl"));
    ExpectEq("You bow to Earl ineptly.\n", Player->caughtMessage());
    ExpectEq("Bob bows to you ineptly.\n", Target->caughtMessage());
    ExpectEq("Bob bows to Earl ineptly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BpokeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bpoke"));
    ExpectEq("You poke an imaginary sea otter and sneer, 'Does this bug you?'\n", Player->caughtMessage());
    ExpectEq("Bob pokes an imaginary sea otter and sneers, 'Does this bug you?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bpoke -a ineptly -t earl"));
    ExpectEq("You ineptly poke Earl and sneer, 'Does this bug you?'\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pokes you and sneers, 'Does this bug you?'\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pokes Earl and sneers, 'Does this bug you?'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BrbDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("brb"));
    ExpectEq("You will be right back (after a word from your sponsors).\n", Player->caughtMessage());
    ExpectEq("Bob will be right back (after a word from his sponsors).\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("brb -a apparently -t earl"));
    ExpectEq("You apparently will be right back (after a word from your sponsors).\n", Player->caughtMessage());
    ExpectEq("Bob apparently will be right back (after a word from his sponsors).\n", Target->caughtMessage());
    ExpectEq("Bob apparently will be right back (after a word from his sponsors).\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BreatheDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("breathe"));
    ExpectEq("You breathe deeply.\n", Player->caughtMessage());
    ExpectEq("Bob breathes deeply.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("breathe -a angrily -t earl"));
    ExpectEq("You breathe angrily.\n", Player->caughtMessage());
    ExpectEq("Bob breathes angrily.\n", Target->caughtMessage());
    ExpectEq("Bob breathes angrily.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BsighDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bsigh"));
    ExpectEq("You sigh indignantly and mutter, `I'm bitter!'\n", Player->caughtMessage());
    ExpectEq("Bob sighs indignantly and mutters, `I'm bitter!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bsigh -a dejectedly -t earl"));
    ExpectEq("You sigh dejectedly at Earl and mutter, `I'm bitter!'\n", Player->caughtMessage());
    ExpectEq("Bob sighs dejectedly at you and mutters, `I'm bitter!'\n", Target->caughtMessage());
    ExpectEq("Bob sighs dejectedly at Earl and mutters, `I'm bitter!'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BullshitDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("bullshit"));
    ExpectEq("You think that is bullshit!\n", Player->caughtMessage());
    ExpectEq("Bob thinks that is bullshit!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("bullshit -a rightfully -t earl"));
    ExpectEq("You rightfully think that is bullshit!\n", Player->caughtMessage());
    ExpectEq("Bob rightfully thinks that is bullshit!\n", Target->caughtMessage());
    ExpectEq("Bob rightfully thinks that is bullshit!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BurpDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("burp"));
    ExpectEq("You burp rudely.\n", Player->caughtMessage());
    ExpectEq("Bob burps rudely.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("burp -a loudly -t earl"));
    ExpectEq("You burp loudly.\n", Player->caughtMessage());
    ExpectEq("Bob burps loudly.\n", Target->caughtMessage());
    ExpectEq("Bob burps loudly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CackleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cackle"));
    ExpectEq("You throw your head back and cackle with glee!\n", Player->caughtMessage());
    ExpectEq("Bob throws his head back and cackles with glee!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cackle -a evilly -t earl"));
    ExpectEq("You throw your head back and cackle at Earl evilly!\n", Player->caughtMessage());
    ExpectEq("Bob throws his head back and cackles at you evilly!\n", Target->caughtMessage());
    ExpectEq("Bob throws his head back and cackles at Earl evilly!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CaressDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("caress"));
    ExpectEq("You gently run your finger down an invisible, deaf mime's cheek.\n", Player->caughtMessage());
    ExpectEq("Bob gently runs his finger down an invisible, deaf mime's cheek.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("caress -a ineptly -t earl"));
    ExpectEq("You ineptly run your finger down Earl's cheek.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly runs his finger down your cheek.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly runs his finger down Earl's cheek.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CheerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cheer"));
    ExpectEq("You cheer enthusiastically.\n", Player->caughtMessage());
    ExpectEq("Bob cheers enthusiastically.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cheer -a ineptly -t earl"));
    ExpectEq("You cheer ineptly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob cheers ineptly at you.\n", Target->caughtMessage());
    ExpectEq("Bob cheers ineptly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CherryDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cherry"));
    ExpectEq("You gobble up a bowl of cherries.\n", Player->caughtMessage());
    ExpectEq("Bob gobbles up a bowl of cherries.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cherry -a ineptly -t earl"));
    ExpectEq("You ineptly gobble up a bowl of cherries.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gobbles up a bowl of cherries.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gobbles up a bowl of cherries.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChewDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("chew"));
    ExpectEq("You chew on something.\n", Player->caughtMessage());
    ExpectEq("Bob chews on something.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("chew -a ineptly -t earl"));
    ExpectEq("You ineptly chew on something.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly chews on something.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly chews on something.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChirpDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("chirp"));
    ExpectEq("You chirp merrily.\n", Player->caughtMessage());
    ExpectEq("Bob chirps merrily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("chirp -a ineptly -t earl"));
    ExpectEq("You chirp ineptly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob chirps ineptly at you.\n", Target->caughtMessage());
    ExpectEq("Bob chirps ineptly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChokeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("choke"));
    ExpectEq("You choke.\n", Player->caughtMessage());
    ExpectEq("Bob chokes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("choke -a ineptly -t earl"));
    ExpectEq("You ineptly choke Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly chokes you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly chokes Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChortleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("chortle"));
    ExpectEq("You chortle gleefully.\n", Player->caughtMessage());
    ExpectEq("Bob chortles gleefully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("chortle -a loudly -t earl"));
    ExpectEq("You chortle loudly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob chortles loudly at you.\n", Target->caughtMessage());
    ExpectEq("Bob chortles loudly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChuckleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("chuckle"));
    ExpectEq("You chuckle politely.\n", Player->caughtMessage());
    ExpectEq("Bob chuckles politely.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("chuckle -a inappropriately -t earl"));
    ExpectEq("You chuckle inappropriately at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob chuckles inappropriately at you.\n", Target->caughtMessage());
    ExpectEq("Bob chuckles inappropriately at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ClapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("clap"));
    ExpectEq("You clap briefly.\n", Player->caughtMessage());
    ExpectEq("Bob claps briefly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("clap -a ineptly -t earl"));
    ExpectEq("You clap ineptly to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob claps ineptly to you.\n", Target->caughtMessage());
    ExpectEq("Bob claps ineptly to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ComfortDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("comfort"));
    ExpectEq("You comfort a small rock.\n", Player->caughtMessage());
    ExpectEq("Bob comforts a small rock.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("comfort -a ineptly -t earl"));
    ExpectEq("You ineptly comfort Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly comforts you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly comforts Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CongratulateDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("congratulate"));
    ExpectEq("You congratulate yourself on a job well done.\n", Player->caughtMessage());
    ExpectEq("Bob congratulates himself on a job well done.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("congratulate -a ineptly -t earl"));
    ExpectEq("You ineptly congratulate Earl on a job well done.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly congratulates you on a job well done.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly congratulates Earl on a job well done.\n", Bystander->caughtMessage())
        ;
}

/////////////////////////////////////////////////////////////////////////////
void CoughDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cough"));
    ExpectEq("You cough noisily.\n", Player->caughtMessage());
    ExpectEq("Bob coughs noisily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cough -a knowingly -t earl"));
    ExpectEq("You cough knowingly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob coughs knowingly at you.\n", Target->caughtMessage());
    ExpectEq("Bob coughs knowingly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CowerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cower"));
    ExpectEq("You cower in a corner.\n", Player->caughtMessage());
    ExpectEq("Bob cowers in a corner.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cower -a ineptly -t earl"));
    ExpectEq("You ineptly cower from Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly cowers from you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly cowers from Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CrackDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("crack"));
    ExpectEq("You crack your knuckles.\n", Player->caughtMessage());
    ExpectEq("Bob cracks his knuckles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("crack -a ineptly -t earl"));
    ExpectEq("You ineptly crack your knuckles.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly cracks his knuckles.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly cracks his knuckles.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CringeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cringe"));
    ExpectEq("You cringe in terror.\n", Player->caughtMessage());
    ExpectEq("Bob cringes in terror.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cringe -a ineptly -t earl"));
    ExpectEq("You cringe ineptly from Earl.\n", Player->caughtMessage());
    ExpectEq("Bob cringes ineptly from you.\n", Target->caughtMessage());
    ExpectEq("Bob cringes ineptly from Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CrossDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cross"));
    ExpectEq("You cross your fingers.\n", Player->caughtMessage());
    ExpectEq("Bob crosses his fingers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cross -a ineptly -t earl"));
    ExpectEq("You ineptly cross your fingers.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CryDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cry"));
    ExpectEq("You burst into tears.\n", Player->caughtMessage());
    ExpectEq("Bob bursts into tears.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cry -a ineptly -t earl"));
    ExpectEq("You ineptly burst into tears.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CuddleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("cuddle"));
    ExpectEq("You cuddle yourself tenderly.\n", Player->caughtMessage());
    ExpectEq("Bob cuddles himself tenderly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("cuddle -a closely -t earl"));
    ExpectEq("You cuddle Earl closely.\n", Player->caughtMessage());
    ExpectEq("Bob cuddles you closely.\n", Target->caughtMessage());
    ExpectEq("Bob cuddles Earl closely.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CurtseyDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("curtsey"));
    ExpectEq("You curtsey gracefully.\n", Player->caughtMessage());
    ExpectEq("Bob curtseys gracefully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("curtsey -a ineptly -t earl"));
    ExpectEq("You curtsey to Earl ineptly.\n", Player->caughtMessage());
    ExpectEq("Bob curtseys to you ineptly.\n", Target->caughtMessage());
    ExpectEq("Bob curtseys to Earl ineptly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DammitDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("dammit"));
    ExpectEq("You say, `DAMMIT!'.\n", Player->caughtMessage());
    ExpectEq("Bob says, `DAMMIT!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("dammit -a disgustedly -t earl"));
    ExpectEq("You disgustedly say, `DAMMIT!' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob disgustedly says, `DAMMIT!' to you.\n", Target->caughtMessage());
    ExpectEq("Bob disgustedly says, `DAMMIT!' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DanceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("dance"));
    ExpectEq("You dance happily.\n", Player->caughtMessage());
    ExpectEq("Bob dances happily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("dance -a ineptly -t earl"));
    ExpectEq("You ineptly dance with Earl, sweeping him across the dance floor.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly dances with you, sweeping you across the dance floor.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly dances with Earl, sweeping him across the dance floor.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DaydreamDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("daydream"));
    ExpectEq("You get lost in a daydream.\n", Player->caughtMessage());
    ExpectEq("Bob gets lost in a daydream.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("daydream -a wistfully -t earl"));
    ExpectEq("You wistfully get lost in a daydream about Earl.\n", Player->caughtMessage());
    ExpectEq("Bob wistfully gets lost in a daydream about you.\n", Target->caughtMessage());
    ExpectEq("Bob wistfully gets lost in a daydream about Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("die"));
    ExpectEq("You roll over and do your best to look dead.\n", Player->caughtMessage());
    ExpectEq("Bob rolls over and does his best to look dead.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("die -a ineptly -t earl"));
    ExpectEq("You roll over ineptly and do your best to look dead.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisagreeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("disagree"));
    ExpectEq("You disagree.\n", Player->caughtMessage());
    ExpectEq("Bob disagrees.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("disagree -a ineptly -t earl"));
    ExpectEq("You ineptly disagree with Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly disagrees with you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly disagrees with Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DohDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("doh"));
    ExpectEq("You smack your head and go, `Doh!'\n", Player->caughtMessage());
    ExpectEq("Bob smacks his head and goes, `Doh!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("doh -a ineptly -t earl"));
    ExpectEq("You ineptly smack your head and go, `Doh!'\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DroolDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("drool"));
    ExpectEq("You drool all over yourself.\n", Player->caughtMessage());
    ExpectEq("Bob drools all over himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("drool -a ineptly -t earl"));
    ExpectEq("You ineptly drool all over Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly drools all over you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly drools all over Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DuckDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("duck"));
    ExpectEq("You duck out of the way.\n", Player->caughtMessage());
    ExpectEq("Bob ducks out of the way.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("duck -a ineptly -t earl"));
    ExpectEq("You ineptly duck out of the way.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ducks out of the way.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ducks out of the way.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DuhDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("duh"));
    ExpectEq("You scream `DUH!'.\n", Player->caughtMessage());
    ExpectEq("Bob screams `DUH!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("duh -a ineptly -t earl"));
    ExpectEq("You ineptly scream `DUH!' at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly screams `DUH!' at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly screams `DUH!' at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EekDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("eek"));
    ExpectEq("You go 'eeeeeeeeeeeeek!'.\n", Player->caughtMessage());
    ExpectEq("Bob goes 'eeeeeeeeeeeeek!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("eek -a ineptly -t earl"));
    ExpectEq("You ineptly go 'eeeeeeeeeeeeek!' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes 'eeeeeeeeeeeeek!' to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes 'eeeeeeeeeeeeek!' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EepDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("eep"));
    ExpectEq("You go 'EEEEP!'.\n", Player->caughtMessage());
    ExpectEq("Bob goes 'EEEEP!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("eep -a ineptly -t earl"));
    ExpectEq("You ineptly go 'EEEEP!' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes 'EEEEP!' to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes 'EEEEP!' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EgrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("egrin"));
    ExpectEq("You grin evilly.\n", Player->caughtMessage());
    ExpectEq("Bob grins evilly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("egrin -a stupidly -t earl"));
    ExpectEq("You grin stupidly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob grins stupidly at you.\n", Target->caughtMessage());
    ExpectEq("Bob grins stupidly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EhDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("eh"));
    ExpectEq("You say, `EH?'\n", Player->caughtMessage());
    ExpectEq("Bob says, `EH?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("eh -a ineptly"));
    ExpectEq("You ineptly say, `EH?'\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EmbarrassDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("embarrass"));
    ExpectEq("You are really embarrassed!\n", Player->caughtMessage());
    ExpectEq("Bob is really embarrassed!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("embarrass -a terribly"));
    ExpectEq("You are terribly embarrassed!\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EmbraceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("embrace"));
    ExpectEq("You gather yourself in a warm, loving embrace.\n", Player->caughtMessage());
    ExpectEq("Bob gathers himself in a warm, loving embrace.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("embrace -a tenderly -t earl"));
    ExpectEq("You tenderly gather Earl in a warm, loving embrace.\n", Player->caughtMessage());
    ExpectEq("Bob tenderly gathers you in a warm, loving embrace.\n", Target->caughtMessage());
    ExpectEq("Bob tenderly gathers Earl in a warm, loving embrace.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExplodeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("explode"));
    ExpectEq("You explode all over the room!\n", Player->caughtMessage());
    ExpectEq("Bob explodes all over the room!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("explode -a ineptly -t earl"));
    ExpectEq("You ineptly explode at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly explodes at you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly explodes at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FaintDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("faint"));
    ExpectEq("You faint... THUMP!\n", Player->caughtMessage());
    ExpectEq("Bob faints... THUMP!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("faint -a ineptly"));
    ExpectEq("You ineptly faint... THUMP!\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FartDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("fart"));
    ExpectEq("You let off a real rip-roarer.\n", Player->caughtMessage());
    ExpectEq("Bob lets off a real rip-roarer.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("fart -a ineptly -t earl"));
    ExpectEq("You ineptly let off a real rip-roarer at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly lets off a real rip-roarer at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly lets off a real rip-roarer at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FearDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("fear"));
    ExpectEq("You shiver with fear.\n", Player->caughtMessage());
    ExpectEq("Bob shivers with fear.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("fear -a ineptly -t earl"));
    ExpectEq("You shiver ineptly with fear from Earl.\n", Player->caughtMessage());
    ExpectEq("Bob shivers ineptly with fear from you.\n", Target->caughtMessage());
    ExpectEq("Bob shivers ineptly with fear from Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlashDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flash"));
    ExpectEq("You strip your clothes and bare your body for all to see!\n", Player->caughtMessage());
    ExpectEq("Bob strips his clothes and bares his body for all to see!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flash -a ineptly -t earl"));
    ExpectEq("Bob ineptly strips his clothes and bares his body for all to see!\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlexDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flex"));
    ExpectEq("You flex your muscles!\n", Player->caughtMessage());
    ExpectEq("Bob flexes his muscles!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flex -a ineptly -t earl"));
    ExpectEq("You ineptly flex your muscles at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly flexes his muscles at you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly flexes his muscles at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlipDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flip"));
    ExpectEq("You flip head over heels.\n", Player->caughtMessage());
    ExpectEq("Bob flips head over heels.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flip -a clumbsily"));
    ExpectEq("You clumbsily flip head over heels.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlipoffDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flipoff"));
    ExpectEq("You give yourself the finger!\n", Player->caughtMessage());
    ExpectEq("Bob gives himself the finger!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flipoff -a vehemently -t earl"));
    ExpectEq("You vehemently give Earl the finger!\n", Player->caughtMessage());
    ExpectEq("Bob vehemently gives you the finger!\n", Target->caughtMessage());
    ExpectEq("Bob vehemently gives Earl the finger!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlirtDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flirt"));
    ExpectEq("You flirt with disaster.\n", Player->caughtMessage());
    ExpectEq("Bob flirts with disaster.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flirt -a ineptly -t earl"));
    ExpectEq("You ineptly flirt with Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly flirts with you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly flirts with Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlogDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flog"));
    ExpectEq("You flog an invisible, mute mime!\n", Player->caughtMessage());
    ExpectEq("Bob flogs an invisible, mute mime!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flog -a ineptly -t earl"));
    ExpectEq("You ineptly flog Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly flogs you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly flogs Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlopDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("flop"));
    ExpectEq("You flop to the floor... FLOP!\n", Player->caughtMessage());
    ExpectEq("Bob flops to the floor... FLOP!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("flop -a dejectedly -t earl"));
    ExpectEq("You dejectedly flop to the floor... FLOP!\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FlyDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("fly"));
    ExpectEq("You put out your arms and run around like a flying bird.\n", Player->caughtMessage());
    ExpectEq("Bob puts out his arms and runs around like a flying bird.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("fly -a abruptly"));
    ExpectEq("You put out your arms abruptly and run around like a flying bird.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FondleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("fondle"));
    ExpectEq("You fondle yourself.\n", Player->caughtMessage());
    ExpectEq("Bob fondles himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("fondle -a ineptly -t earl"));
    ExpectEq("You ineptly fondle Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly fondles you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly fondles Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FreezeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("freeze"));
    ExpectEq("You freeze and turn into a popsicle!\n", Player->caughtMessage());
    ExpectEq("Bob freezes and turns into a popsicle!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("freeze -a ineptly -t earl"));
    ExpectEq("You freeze ineptly and turn into a popsicle!\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FrenchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("french"));
    ExpectEq("You give an invisible toad a deep, hot, passionate kiss...it seems to last\nforever.\n", Player->caughtMessage());
    ExpectEq("Bob gives an invisible toad a deep, hot, passionate kiss...it seems to last\nforever.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("french -a ineptly -t earl"));
    ExpectEq("You ineptly give Earl a deep, hot, passionate kiss...it seems to last forever.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gives you a deep, hot, passionate kiss...it seems to last forever.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gives Earl a deep, hot, passionate kiss...it seems to last\nforever.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FrownDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("frown"));
    ExpectEq("You frown.\n", Player->caughtMessage());
    ExpectEq("Bob frowns.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("frown -a ineptly -t earl"));
    ExpectEq("You ineptly frown at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly frowns at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly frowns at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FumeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("fume"));
    ExpectEq("You fume.\n", Player->caughtMessage());
    ExpectEq("Bob fumes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("fume -a ineptly -t earl"));
    ExpectEq("You ineptly fume at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly fumes at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly fumes at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GagDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("gag"));
    ExpectEq("You gag.\n", Player->caughtMessage());
    ExpectEq("Bob gags.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("gag -a ineptly -t earl"));
    ExpectEq("You ineptly gag at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gags at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gags at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GaspDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("gasp"));
    ExpectEq("You gasp in astonishment.\n", Player->caughtMessage());
    ExpectEq("Bob gasps in astonishment.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("gasp -a disgustedly -t earl"));
    ExpectEq("You gasp disgustedly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob gasps disgustedly at you.\n", Target->caughtMessage());
    ExpectEq("Bob gasps disgustedly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GclapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("gclap"));
    ExpectEq("You golf clap.\n", Player->caughtMessage());
    ExpectEq("Bob golf claps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("gclap -a ineptly -t earl"));
    ExpectEq("You ineptly golf clap at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly golf claps at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly golf claps at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GibberDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("gibber"));
    ExpectEq("You gibber like a madman.\n", Player->caughtMessage());
    ExpectEq("Bob gibbers like a madman.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("gibber -a grotesquely -t earl"));
    ExpectEq("You grotesquely gibber at Earl like a madman.\n", Player->caughtMessage());
    ExpectEq("Bob grotesquely gibbers at you like a madman.\n", Target->caughtMessage());
    ExpectEq("Bob grotesquely gibbers at Earl like a madman.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GiggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("giggle"));
    ExpectEq("You giggle happily.\n", Player->caughtMessage());
    ExpectEq("Bob giggles happily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("giggle -a inappropriately -t earl"));
    ExpectEq("You giggle inappropriately at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob giggles inappropriately at you.\n", Target->caughtMessage());
    ExpectEq("Bob giggles inappropriately at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GlareDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("glare"));
    ExpectEq("You glare icily.\n", Player->caughtMessage());
    ExpectEq("Bob glares icily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("glare -a stonily -t earl"));
    ExpectEq("You glare stonily at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob glares stonily at you.\n", Target->caughtMessage());
    ExpectEq("Bob glares stonily at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GloatDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("gloat"));
    ExpectEq("You gloat foolishly.\n", Player->caughtMessage());
    ExpectEq("Bob gloats foolishly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("gloat -a annoyingly -t earl"));
    ExpectEq("You gloat annoyingly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob gloats annoyingly at you.\n", Target->caughtMessage());
    ExpectEq("Bob gloats annoyingly at Earl.\n", Bystander->caughtMessage());
}
/*
/////////////////////////////////////////////////////////////////////////////
void GooDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("goo"));
    ExpectEq("You goo.\n", Player->caughtMessage());
    ExpectEq("Bob goos.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("goo -a ineptly -t earl"));
    ExpectEq("You ineptly goo to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goos to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goos to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GooseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("goose"));
    ExpectEq("You goose.\n", Player->caughtMessage());
    ExpectEq("Bob gooses.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("goose -a ineptly -t earl"));
    ExpectEq("You ineptly goose to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gooses to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gooses to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrabDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grab"));
    ExpectEq("You grab.\n", Player->caughtMessage());
    ExpectEq("Bob grabs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grab -a ineptly -t earl"));
    ExpectEq("You ineptly grab to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grabs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grabs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrimaceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grimace"));
    ExpectEq("You grimace.\n", Player->caughtMessage());
    ExpectEq("Bob grimaces.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grimace -a ineptly -t earl"));
    ExpectEq("You ineptly grimace to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grimaces to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grimaces to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grin"));
    ExpectEq("You grin.\n", Player->caughtMessage());
    ExpectEq("Bob grins.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grin -a ineptly -t earl"));
    ExpectEq("You ineptly grin to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grins to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grins to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GroanDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("groan"));
    ExpectEq("You groan.\n", Player->caughtMessage());
    ExpectEq("Bob groans.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("groan -a ineptly -t earl"));
    ExpectEq("You ineptly groan to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly groans to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly groans to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GropeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grope"));
    ExpectEq("You grope.\n", Player->caughtMessage());
    ExpectEq("Bob gropes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grope -a ineptly -t earl"));
    ExpectEq("You ineptly grope to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gropes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gropes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrovelDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grovel"));
    ExpectEq("You grovel.\n", Player->caughtMessage());
    ExpectEq("Bob grovels.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grovel -a ineptly -t earl"));
    ExpectEq("You ineptly grovel to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grovels to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grovels to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrowlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("growl"));
    ExpectEq("You growl.\n", Player->caughtMessage());
    ExpectEq("Bob growls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("growl -a ineptly -t earl"));
    ExpectEq("You ineptly growl to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly growls to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly growls to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrumbleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grumble"));
    ExpectEq("You grumble.\n", Player->caughtMessage());
    ExpectEq("Bob grumbles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grumble -a ineptly -t earl"));
    ExpectEq("You ineptly grumble to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grumbles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grumbles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GuffawDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("guffaw"));
    ExpectEq("You guffaw.\n", Player->caughtMessage());
    ExpectEq("Bob guffaws.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("guffaw -a ineptly -t earl"));
    ExpectEq("You ineptly guffaw to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly guffaws to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly guffaws to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HairDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hair"));
    ExpectEq("You hair.\n", Player->caughtMessage());
    ExpectEq("Bob hairs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hair -a ineptly -t earl"));
    ExpectEq("You ineptly hair to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hairs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hairs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HandkissDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("handkiss"));
    ExpectEq("You handkiss.\n", Player->caughtMessage());
    ExpectEq("Bob handkisss.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("handkiss -a ineptly -t earl"));
    ExpectEq("You ineptly handkiss to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly handkisss to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly handkisss to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HarumphDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("harumph"));
    ExpectEq("You harumph.\n", Player->caughtMessage());
    ExpectEq("Bob harumphs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("harumph -a ineptly -t earl"));
    ExpectEq("You ineptly harumph to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly harumphs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly harumphs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HeeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hee"));
    ExpectEq("You hee.\n", Player->caughtMessage());
    ExpectEq("Bob hees.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hee -a ineptly -t earl"));
    ExpectEq("You ineptly hee to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hees to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hees to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HehDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("heh"));
    ExpectEq("You heh.\n", Player->caughtMessage());
    ExpectEq("Bob hehs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("heh -a ineptly -t earl"));
    ExpectEq("You ineptly heh to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hehs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hehs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void Hi5DisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hi5"));
    ExpectEq("You hi5.\n", Player->caughtMessage());
    ExpectEq("Bob hi5s.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hi5 -a ineptly -t earl"));
    ExpectEq("You ineptly hi5 to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hi5s to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hi5s to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HiccupDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hiccup"));
    ExpectEq("You hiccup.\n", Player->caughtMessage());
    ExpectEq("Bob hiccups.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hiccup -a ineptly -t earl"));
    ExpectEq("You ineptly hiccup to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hiccups to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hiccups to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HmmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hmm"));
    ExpectEq("You hmm.\n", Player->caughtMessage());
    ExpectEq("Bob hmms.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hmm -a ineptly -t earl"));
    ExpectEq("You ineptly hmm to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hmms to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hmms to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HoldDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hold"));
    ExpectEq("You hold.\n", Player->caughtMessage());
    ExpectEq("Bob holds.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hold -a ineptly -t earl"));
    ExpectEq("You ineptly hold to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly holds to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly holds to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HopDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hop"));
    ExpectEq("You hop.\n", Player->caughtMessage());
    ExpectEq("Bob hops.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hop -a ineptly -t earl"));
    ExpectEq("You ineptly hop to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hops to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hops to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HowlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("howl"));
    ExpectEq("You howl.\n", Player->caughtMessage());
    ExpectEq("Bob howls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("howl -a ineptly -t earl"));
    ExpectEq("You ineptly howl to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly howls to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly howls to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HrmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hrm"));
    ExpectEq("You hrm.\n", Player->caughtMessage());
    ExpectEq("Bob hrms.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hrm -a ineptly -t earl"));
    ExpectEq("You ineptly hrm to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hrms to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hrms to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HugDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hug"));
    ExpectEq("You hug.\n", Player->caughtMessage());
    ExpectEq("Bob hugs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hug -a ineptly -t earl"));
    ExpectEq("You ineptly hug to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hugs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hugs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HuggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("huggle"));
    ExpectEq("You huggle.\n", Player->caughtMessage());
    ExpectEq("Bob huggles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("huggle -a ineptly -t earl"));
    ExpectEq("You ineptly huggle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly huggles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly huggles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void IgnoreDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ignore"));
    ExpectEq("You ignore.\n", Player->caughtMessage());
    ExpectEq("Bob ignores.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ignore -a ineptly -t earl"));
    ExpectEq("You ineptly ignore to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ignores to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ignores to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InsultDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("insult"));
    ExpectEq("You insult.\n", Player->caughtMessage());
    ExpectEq("Bob insults.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("insult -a ineptly -t earl"));
    ExpectEq("You ineptly insult to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly insults to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly insults to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void JumpDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("jump"));
    ExpectEq("You jump.\n", Player->caughtMessage());
    ExpectEq("Bob jumps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("jump -a ineptly -t earl"));
    ExpectEq("You ineptly jump to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly jumps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly jumps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KickDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("kick"));
    ExpectEq("You kick.\n", Player->caughtMessage());
    ExpectEq("Bob kicks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("kick -a ineptly -t earl"));
    ExpectEq("You ineptly kick to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly kicks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly kicks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KissDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("kiss"));
    ExpectEq("You kiss.\n", Player->caughtMessage());
    ExpectEq("Bob kisss.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("kiss -a ineptly -t earl"));
    ExpectEq("You ineptly kiss to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly kisss to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly kisss to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LaughDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("laugh"));
    ExpectEq("You laugh.\n", Player->caughtMessage());
    ExpectEq("Bob laughs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("laugh -a ineptly -t earl"));
    ExpectEq("You ineptly laugh to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly laughs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly laughs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LdDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ld"));
    ExpectEq("You ld.\n", Player->caughtMessage());
    ExpectEq("Bob lds.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ld -a ineptly -t earl"));
    ExpectEq("You ineptly ld to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly lds to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly lds to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LickDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("lick"));
    ExpectEq("You lick.\n", Player->caughtMessage());
    ExpectEq("Bob licks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("lick -a ineptly -t earl"));
    ExpectEq("You ineptly lick to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly licks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly licks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LolDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("lol"));
    ExpectEq("You lol.\n", Player->caughtMessage());
    ExpectEq("Bob lols.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("lol -a ineptly -t earl"));
    ExpectEq("You ineptly lol to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly lols to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly lols to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LoveDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("love"));
    ExpectEq("You love.\n", Player->caughtMessage());
    ExpectEq("Bob loves.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("love -a ineptly -t earl"));
    ExpectEq("You ineptly love to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly loves to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly loves to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MehDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("meh"));
    ExpectEq("You meh.\n", Player->caughtMessage());
    ExpectEq("Bob mehs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("meh -a ineptly -t earl"));
    ExpectEq("You ineptly meh to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly mehs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly mehs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MgrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mgrin"));
    ExpectEq("You mgrin.\n", Player->caughtMessage());
    ExpectEq("Bob mgrins.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mgrin -a ineptly -t earl"));
    ExpectEq("You ineptly mgrin to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly mgrins to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly mgrins to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoanDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("moan"));
    ExpectEq("You moan.\n", Player->caughtMessage());
    ExpectEq("Bob moans.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("moan -a ineptly -t earl"));
    ExpectEq("You ineptly moan to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly moans to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly moans to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MockDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mock"));
    ExpectEq("You mock.\n", Player->caughtMessage());
    ExpectEq("Bob mocks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mock -a ineptly -t earl"));
    ExpectEq("You ineptly mock to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly mocks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly mocks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MstampDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mstamp"));
    ExpectEq("You mstamp.\n", Player->caughtMessage());
    ExpectEq("Bob mstamps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mstamp -a ineptly -t earl"));
    ExpectEq("You ineptly mstamp to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly mstamps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly mstamps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MuffleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("muffle"));
    ExpectEq("You muffle.\n", Player->caughtMessage());
    ExpectEq("Bob muffles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("muffle -a ineptly -t earl"));
    ExpectEq("You ineptly muffle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly muffles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly muffles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NibbleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nibble"));
    ExpectEq("You nibble.\n", Player->caughtMessage());
    ExpectEq("Bob nibbles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nibble -a ineptly -t earl"));
    ExpectEq("You ineptly nibble to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nibbles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nibbles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NodDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nod"));
    ExpectEq("You nod.\n", Player->caughtMessage());
    ExpectEq("Bob nods.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nod -a ineptly -t earl"));
    ExpectEq("You ineptly nod to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nods to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nods to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NogDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nog"));
    ExpectEq("You nog.\n", Player->caughtMessage());
    ExpectEq("Bob nogs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nog -a ineptly -t earl"));
    ExpectEq("You ineptly nog to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nogs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nogs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoogieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("noogie"));
    ExpectEq("You noogie.\n", Player->caughtMessage());
    ExpectEq("Bob noogies.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("noogie -a ineptly -t earl"));
    ExpectEq("You ineptly noogie to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly noogies to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly noogies to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NudgeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nudge"));
    ExpectEq("You nudge.\n", Player->caughtMessage());
    ExpectEq("Bob nudges.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nudge -a ineptly -t earl"));
    ExpectEq("You ineptly nudge to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nudges to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nudges to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NurseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nurse"));
    ExpectEq("You nurse.\n", Player->caughtMessage());
    ExpectEq("Bob nurses.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nurse -a ineptly -t earl"));
    ExpectEq("You ineptly nurse to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nurses to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nurses to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NuzzleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nuzzle"));
    ExpectEq("You nuzzle.\n", Player->caughtMessage());
    ExpectEq("Bob nuzzles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nuzzle -a ineptly -t earl"));
    ExpectEq("You ineptly nuzzle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nuzzles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nuzzles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OuchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ouch"));
    ExpectEq("You ouch.\n", Player->caughtMessage());
    ExpectEq("Bob ouchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ouch -a ineptly -t earl"));
    ExpectEq("You ineptly ouch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ouchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ouchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PaceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pace"));
    ExpectEq("You pace.\n", Player->caughtMessage());
    ExpectEq("Bob paces.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pace -a ineptly -t earl"));
    ExpectEq("You ineptly pace to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly paces to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly paces to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PanicDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("panic"));
    ExpectEq("You panic.\n", Player->caughtMessage());
    ExpectEq("Bob panics.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("panic -a ineptly -t earl"));
    ExpectEq("You ineptly panic to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly panics to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly panics to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PatDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pat"));
    ExpectEq("You pat.\n", Player->caughtMessage());
    ExpectEq("Bob pats.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pat -a ineptly -t earl"));
    ExpectEq("You ineptly pat to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pats to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pats to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PeerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("peer"));
    ExpectEq("You peer.\n", Player->caughtMessage());
    ExpectEq("Bob peers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("peer -a ineptly -t earl"));
    ExpectEq("You ineptly peer to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly peers to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly peers to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PfftDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pfft"));
    ExpectEq("You pfft.\n", Player->caughtMessage());
    ExpectEq("Bob pffts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pfft -a ineptly -t earl"));
    ExpectEq("You ineptly pfft to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pffts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pffts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PinchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pinch"));
    ExpectEq("You pinch.\n", Player->caughtMessage());
    ExpectEq("Bob pinchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pinch -a ineptly -t earl"));
    ExpectEq("You ineptly pinch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pinchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pinchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PizzaDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pizza"));
    ExpectEq("You pizza.\n", Player->caughtMessage());
    ExpectEq("Bob pizzas.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pizza -a ineptly -t earl"));
    ExpectEq("You ineptly pizza to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pizzas to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pizzas to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PleaseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("please"));
    ExpectEq("You please.\n", Player->caughtMessage());
    ExpectEq("Bob pleases.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("please -a ineptly -t earl"));
    ExpectEq("You ineptly please to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pleases to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pleases to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PointDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("point"));
    ExpectEq("You point.\n", Player->caughtMessage());
    ExpectEq("Bob points.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("point -a ineptly -t earl"));
    ExpectEq("You ineptly point to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly points to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly points to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PokeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("poke"));
    ExpectEq("You poke.\n", Player->caughtMessage());
    ExpectEq("Bob pokes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("poke -a ineptly -t earl"));
    ExpectEq("You ineptly poke to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pokes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pokes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PonderDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ponder"));
    ExpectEq("You ponder.\n", Player->caughtMessage());
    ExpectEq("Bob ponders.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ponder -a ineptly -t earl"));
    ExpectEq("You ineptly ponder to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ponders to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ponders to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PounceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pounce"));
    ExpectEq("You pounce.\n", Player->caughtMessage());
    ExpectEq("Bob pounces.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pounce -a ineptly -t earl"));
    ExpectEq("You ineptly pounce to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pounces to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pounces to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PoutDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pout"));
    ExpectEq("You pout.\n", Player->caughtMessage());
    ExpectEq("Bob pouts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pout -a ineptly -t earl"));
    ExpectEq("You ineptly pout to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pouts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pouts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PukeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("puke"));
    ExpectEq("You puke.\n", Player->caughtMessage());
    ExpectEq("Bob pukes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("puke -a ineptly -t earl"));
    ExpectEq("You ineptly puke to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pukes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pukes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PunchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("punch"));
    ExpectEq("You punch.\n", Player->caughtMessage());
    ExpectEq("Bob punchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("punch -a ineptly -t earl"));
    ExpectEq("You ineptly punch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly punchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly punchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PurrDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("purr"));
    ExpectEq("You purr.\n", Player->caughtMessage());
    ExpectEq("Bob purrs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("purr -a ineptly -t earl"));
    ExpectEq("You ineptly purr to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly purrs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly purrs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PuzzleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("puzzle"));
    ExpectEq("You puzzle.\n", Player->caughtMessage());
    ExpectEq("Bob puzzles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("puzzle -a ineptly -t earl"));
    ExpectEq("You ineptly puzzle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly puzzles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly puzzles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RaiseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("raise"));
    ExpectEq("You raise.\n", Player->caughtMessage());
    ExpectEq("Bob raises.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("raise -a ineptly -t earl"));
    ExpectEq("You ineptly raise to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly raises to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly raises to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RdanceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("rdance"));
    ExpectEq("You rdance.\n", Player->caughtMessage());
    ExpectEq("Bob rdances.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("rdance -a ineptly -t earl"));
    ExpectEq("You ineptly rdance to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly rdances to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly rdances to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RecoilDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("recoil"));
    ExpectEq("You recoil.\n", Player->caughtMessage());
    ExpectEq("Bob recoils.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("recoil -a ineptly -t earl"));
    ExpectEq("You ineptly recoil to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly recoils to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly recoils to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RoflDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("rofl"));
    ExpectEq("You rofl.\n", Player->caughtMessage());
    ExpectEq("Bob rofls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("rofl -a ineptly -t earl"));
    ExpectEq("You ineptly rofl to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly rofls to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly rofls to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RollDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("roll"));
    ExpectEq("You roll.\n", Player->caughtMessage());
    ExpectEq("Bob rolls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("roll -a ineptly -t earl"));
    ExpectEq("You ineptly roll to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly rolls to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly rolls to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RuffleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ruffle"));
    ExpectEq("You ruffle.\n", Player->caughtMessage());
    ExpectEq("Bob ruffles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ruffle -a ineptly -t earl"));
    ExpectEq("You ineptly ruffle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ruffles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ruffles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScratchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("scratch"));
    ExpectEq("You scratch.\n", Player->caughtMessage());
    ExpectEq("Bob scratchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("scratch -a ineptly -t earl"));
    ExpectEq("You ineptly scratch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly scratchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly scratchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScreamDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("scream"));
    ExpectEq("You scream.\n", Player->caughtMessage());
    ExpectEq("Bob screams.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("scream -a ineptly -t earl"));
    ExpectEq("You ineptly scream to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly screams to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly screams to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShakeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shake"));
    ExpectEq("You shake.\n", Player->caughtMessage());
    ExpectEq("Bob shakes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shake -a ineptly -t earl"));
    ExpectEq("You ineptly shake to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shakes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shakes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShhDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shh"));
    ExpectEq("You shh.\n", Player->caughtMessage());
    ExpectEq("Bob shhs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shh -a ineptly -t earl"));
    ExpectEq("You ineptly shh to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shhs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shhs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShiverDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shiver"));
    ExpectEq("You shiver.\n", Player->caughtMessage());
    ExpectEq("Bob shivers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shiver -a ineptly -t earl"));
    ExpectEq("You ineptly shiver to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shivers to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shivers to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShiversDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shivers"));
    ExpectEq("You shivers.\n", Player->caughtMessage());
    ExpectEq("Bob shiverss.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shivers -a ineptly -t earl"));
    ExpectEq("You ineptly shivers to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shiverss to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shiverss to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShrugDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shrug"));
    ExpectEq("You shrug.\n", Player->caughtMessage());
    ExpectEq("Bob shrugs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shrug -a ineptly -t earl"));
    ExpectEq("You ineptly shrug to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shrugs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shrugs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShudderDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shudder"));
    ExpectEq("You shudder.\n", Player->caughtMessage());
    ExpectEq("Bob shudders.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shudder -a ineptly -t earl"));
    ExpectEq("You ineptly shudder to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shudders to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shudders to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SighDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sigh"));
    ExpectEq("You sigh.\n", Player->caughtMessage());
    ExpectEq("Bob sighs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sigh -a ineptly -t earl"));
    ExpectEq("You ineptly sigh to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sighs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sighs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SingDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sing"));
    ExpectEq("You sing.\n", Player->caughtMessage());
    ExpectEq("Bob sings.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sing -a ineptly -t earl"));
    ExpectEq("You ineptly sing to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sings to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sings to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SlapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("slap"));
    ExpectEq("You slap.\n", Player->caughtMessage());
    ExpectEq("Bob slaps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("slap -a ineptly -t earl"));
    ExpectEq("You ineptly slap to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly slaps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly slaps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmileDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smile"));
    ExpectEq("You smile.\n", Player->caughtMessage());
    ExpectEq("Bob smiles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smile -a ineptly -t earl"));
    ExpectEq("You ineptly smile to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly smiles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly smiles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmirkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smirk"));
    ExpectEq("You smirk.\n", Player->caughtMessage());
    ExpectEq("Bob smirks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smirk -a ineptly -t earl"));
    ExpectEq("You ineptly smirk to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly smirks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly smirks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmoochDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smooch"));
    ExpectEq("You smooch.\n", Player->caughtMessage());
    ExpectEq("Bob smoochs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smooch -a ineptly -t earl"));
    ExpectEq("You ineptly smooch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly smoochs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly smoochs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snap"));
    ExpectEq("You snap.\n", Player->caughtMessage());
    ExpectEq("Bob snaps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snap -a ineptly -t earl"));
    ExpectEq("You ineptly snap to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snaps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snaps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnarlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snarl"));
    ExpectEq("You snarl.\n", Player->caughtMessage());
    ExpectEq("Bob snarls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snarl -a ineptly -t earl"));
    ExpectEq("You ineptly snarl to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snarls to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snarls to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SneezeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sneeze"));
    ExpectEq("You sneeze.\n", Player->caughtMessage());
    ExpectEq("Bob sneezes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sneeze -a ineptly -t earl"));
    ExpectEq("You ineptly sneeze to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sneezes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sneezes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnickerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snicker"));
    ExpectEq("You snicker.\n", Player->caughtMessage());
    ExpectEq("Bob snickers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snicker -a ineptly -t earl"));
    ExpectEq("You ineptly snicker to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snickers to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snickers to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SniffDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sniff"));
    ExpectEq("You sniff.\n", Player->caughtMessage());
    ExpectEq("Bob sniffs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sniff -a ineptly -t earl"));
    ExpectEq("You ineptly sniff to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sniffs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sniffs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnoreDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snore"));
    ExpectEq("You snore.\n", Player->caughtMessage());
    ExpectEq("Bob snores.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snore -a ineptly -t earl"));
    ExpectEq("You ineptly snore to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snores to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snores to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnortDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snort"));
    ExpectEq("You snort.\n", Player->caughtMessage());
    ExpectEq("Bob snorts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snort -a ineptly -t earl"));
    ExpectEq("You ineptly snort to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snorts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snorts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnuggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snuggle"));
    ExpectEq("You snuggle.\n", Player->caughtMessage());
    ExpectEq("Bob snuggles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snuggle -a ineptly -t earl"));
    ExpectEq("You ineptly snuggle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snuggles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snuggles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SobDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sob"));
    ExpectEq("You sob.\n", Player->caughtMessage());
    ExpectEq("Bob sobs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sob -a ineptly -t earl"));
    ExpectEq("You ineptly sob to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sobs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sobs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpankDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("spank"));
    ExpectEq("You spank.\n", Player->caughtMessage());
    ExpectEq("Bob spanks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("spank -a ineptly -t earl"));
    ExpectEq("You ineptly spank to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly spanks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly spanks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpitDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("spit"));
    ExpectEq("You spit.\n", Player->caughtMessage());
    ExpectEq("Bob spits.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("spit -a ineptly -t earl"));
    ExpectEq("You ineptly spit to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly spits to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly spits to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SqueezeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("squeeze"));
    ExpectEq("You squeeze.\n", Player->caughtMessage());
    ExpectEq("Bob squeezes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("squeeze -a ineptly -t earl"));
    ExpectEq("You ineptly squeeze to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly squeezes to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly squeezes to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SquirmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("squirm"));
    ExpectEq("You squirm.\n", Player->caughtMessage());
    ExpectEq("Bob squirms.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("squirm -a ineptly -t earl"));
    ExpectEq("You ineptly squirm to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly squirms to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly squirms to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StareDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stare"));
    ExpectEq("You stare.\n", Player->caughtMessage());
    ExpectEq("Bob stares.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stare -a ineptly -t earl"));
    ExpectEq("You ineptly stare to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly stares to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly stares to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StartDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("start"));
    ExpectEq("You start.\n", Player->caughtMessage());
    ExpectEq("Bob starts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("start -a ineptly -t earl"));
    ExpectEq("You ineptly start to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly starts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly starts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SteamDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("steam"));
    ExpectEq("You steam.\n", Player->caughtMessage());
    ExpectEq("Bob steams.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("steam -a ineptly -t earl"));
    ExpectEq("You ineptly steam to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly steams to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly steams to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StompDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stomp"));
    ExpectEq("You stomp.\n", Player->caughtMessage());
    ExpectEq("Bob stomps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stomp -a ineptly -t earl"));
    ExpectEq("You ineptly stomp to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly stomps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly stomps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StretchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stretch"));
    ExpectEq("You stretch.\n", Player->caughtMessage());
    ExpectEq("Bob stretchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stretch -a ineptly -t earl"));
    ExpectEq("You ineptly stretch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly stretchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly stretchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StrutDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("strut"));
    ExpectEq("You strut.\n", Player->caughtMessage());
    ExpectEq("Bob struts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("strut -a ineptly -t earl"));
    ExpectEq("You ineptly strut to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly struts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly struts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SulkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sulk"));
    ExpectEq("You sulk.\n", Player->caughtMessage());
    ExpectEq("Bob sulks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sulk -a ineptly -t earl"));
    ExpectEq("You ineptly sulk to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sulks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sulks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SwimDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("swim"));
    ExpectEq("You swim.\n", Player->caughtMessage());
    ExpectEq("Bob swims.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("swim -a ineptly -t earl"));
    ExpectEq("You ineptly swim to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly swims to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly swims to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TackleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tackle"));
    ExpectEq("You tackle.\n", Player->caughtMessage());
    ExpectEq("Bob tackles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tackle -a ineptly -t earl"));
    ExpectEq("You ineptly tackle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tackles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tackles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TahdahDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tahdah"));
    ExpectEq("You tahdah.\n", Player->caughtMessage());
    ExpectEq("Bob tahdahs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tahdah -a ineptly -t earl"));
    ExpectEq("You ineptly tahdah to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tahdahs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tahdahs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tap"));
    ExpectEq("You tap.\n", Player->caughtMessage());
    ExpectEq("Bob taps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tap -a ineptly -t earl"));
    ExpectEq("You ineptly tap to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly taps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly taps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TauntDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("taunt"));
    ExpectEq("You taunt.\n", Player->caughtMessage());
    ExpectEq("Bob taunts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("taunt -a ineptly -t earl"));
    ExpectEq("You ineptly taunt to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly taunts to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly taunts to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TeaseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tease"));
    ExpectEq("You tease.\n", Player->caughtMessage());
    ExpectEq("Bob teases.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tease -a ineptly -t earl"));
    ExpectEq("You ineptly tease to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly teases to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly teases to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThankDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("thank"));
    ExpectEq("You thank.\n", Player->caughtMessage());
    ExpectEq("Bob thanks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("thank -a ineptly -t earl"));
    ExpectEq("You ineptly thank to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly thanks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly thanks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThinkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("think"));
    ExpectEq("You think.\n", Player->caughtMessage());
    ExpectEq("Bob thinks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("think -a ineptly -t earl"));
    ExpectEq("You ineptly think to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly thinks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly thinks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThwapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("thwap"));
    ExpectEq("You thwap.\n", Player->caughtMessage());
    ExpectEq("Bob thwaps.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("thwap -a ineptly -t earl"));
    ExpectEq("You ineptly thwap to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly thwaps to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly thwaps to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TickleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tickle"));
    ExpectEq("You tickle.\n", Player->caughtMessage());
    ExpectEq("Bob tickles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tickle -a ineptly -t earl"));
    ExpectEq("You ineptly tickle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tickles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tickles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TskDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tsk"));
    ExpectEq("You tsk.\n", Player->caughtMessage());
    ExpectEq("Bob tsks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tsk -a ineptly -t earl"));
    ExpectEq("You ineptly tsk to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tsks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tsks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwiddleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("twiddle"));
    ExpectEq("You twiddle.\n", Player->caughtMessage());
    ExpectEq("Bob twiddles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("twiddle -a ineptly -t earl"));
    ExpectEq("You ineptly twiddle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly twiddles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly twiddles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwitchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("twitch"));
    ExpectEq("You twitch.\n", Player->caughtMessage());
    ExpectEq("Bob twitchs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("twitch -a ineptly -t earl"));
    ExpectEq("You ineptly twitch to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly twitchs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly twitchs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WaveDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wave"));
    ExpectEq("You wave.\n", Player->caughtMessage());
    ExpectEq("Bob waves.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wave -a ineptly -t earl"));
    ExpectEq("You ineptly wave to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly waves to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly waves to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WedgieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wedgie"));
    ExpectEq("You wedgie.\n", Player->caughtMessage());
    ExpectEq("Bob wedgies.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wedgie -a ineptly -t earl"));
    ExpectEq("You ineptly wedgie to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly wedgies to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly wedgies to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WeenieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("weenie"));
    ExpectEq("You weenie.\n", Player->caughtMessage());
    ExpectEq("Bob weenies.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("weenie -a ineptly -t earl"));
    ExpectEq("You ineptly weenie to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly weenies to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly weenies to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WeirdDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("weird"));
    ExpectEq("You weird.\n", Player->caughtMessage());
    ExpectEq("Bob weirds.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("weird -a ineptly -t earl"));
    ExpectEq("You ineptly weird to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly weirds to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly weirds to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WellDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("well"));
    ExpectEq("You well.\n", Player->caughtMessage());
    ExpectEq("Bob wells.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("well -a ineptly -t earl"));
    ExpectEq("You ineptly well to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly wells to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly wells to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WheeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whee"));
    ExpectEq("You whee.\n", Player->caughtMessage());
    ExpectEq("Bob whees.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whee -a ineptly -t earl"));
    ExpectEq("You ineptly whee to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly whees to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly whees to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WhineDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whine"));
    ExpectEq("You whine.\n", Player->caughtMessage());
    ExpectEq("Bob whines.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whine -a ineptly -t earl"));
    ExpectEq("You ineptly whine to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly whines to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly whines to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WhistleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whistle"));
    ExpectEq("You whistle.\n", Player->caughtMessage());
    ExpectEq("Bob whistles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whistle -a ineptly -t earl"));
    ExpectEq("You ineptly whistle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly whistles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly whistles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WiggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wiggle"));
    ExpectEq("You wiggle.\n", Player->caughtMessage());
    ExpectEq("Bob wiggles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wiggle -a ineptly -t earl"));
    ExpectEq("You ineptly wiggle to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly wiggles to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly wiggles to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WinkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wink"));
    ExpectEq("You wink.\n", Player->caughtMessage());
    ExpectEq("Bob winks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wink -a ineptly -t earl"));
    ExpectEq("You ineptly wink to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly winks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly winks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WorshipDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("worship"));
    ExpectEq("You worship.\n", Player->caughtMessage());
    ExpectEq("Bob worships.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("worship -a ineptly -t earl"));
    ExpectEq("You ineptly worship to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly worships to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly worships to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YawnDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yawn"));
    ExpectEq("You yawn.\n", Player->caughtMessage());
    ExpectEq("Bob yawns.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yawn -a ineptly -t earl"));
    ExpectEq("You ineptly yawn to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yawns to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yawns to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YayDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yay"));
    ExpectEq("You yay.\n", Player->caughtMessage());
    ExpectEq("Bob yays.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yay -a ineptly -t earl"));
    ExpectEq("You ineptly yay to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yays to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yays to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YeahDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yeah"));
    ExpectEq("You yeah.\n", Player->caughtMessage());
    ExpectEq("Bob yeahs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yeah -a ineptly -t earl"));
    ExpectEq("You ineptly yeah to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yeahs to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yeahs to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YodelDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yodel"));
    ExpectEq("You yodel.\n", Player->caughtMessage());
    ExpectEq("Bob yodels.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yodel -a ineptly -t earl"));
    ExpectEq("You ineptly yodel to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yodels to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yodels to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YuckDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yuck"));
    ExpectEq("You yuck.\n", Player->caughtMessage());
    ExpectEq("Bob yucks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yuck -a ineptly -t earl"));
    ExpectEq("You ineptly yuck to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yucks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yucks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ZingDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("zing"));
    ExpectEq("You zing.\n", Player->caughtMessage());
    ExpectEq("Bob zings.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("zing -a ineptly -t earl"));
    ExpectEq("You ineptly zing to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly zings to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly zings to Earl.\n", Bystander->caughtMessage());
}
*/