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
    Player->colorConfiguration("none");
    Player->addCommands();
    move_object(Player, this_object());

    Target = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target->Name("earl");
    Target->Race("human");
    Target->Gender(1);
    Target->colorConfiguration("none");
    Target->addCommands();
    move_object(Target, this_object());

    Bystander = clone_object("/lib/tests/support/services/mockPlayer.c");
    Bystander->Name("frank");
    Bystander->Race("human");
    Bystander->Gender(1);
    Bystander->colorConfiguration("none");
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
    ExpectTrue(Player->executeCommand("ack -t frank"));
    ExpectEq("You ack at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob acks at Frank.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ack -a stupidly -t earl"));
    ExpectEq("You stupidly ack at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob stupidly acks at you.\n", Target->caughtMessage());
    ExpectEq("Bob stupidly acks at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AckWithNoFlagsButImplicitTargetHandledCorrectly()
{
    ExpectTrue(Player->executeCommand("ack earl"));
    ExpectEq("You ack at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob acks at you.\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AdmireDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("admire"));
    ExpectEq("You admire the ambiguity of admiring without a target.\n", Player->caughtMessage());
    ExpectEq("Bob admires the ambiguity of admiring without a target.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("admire -t frank"));
    ExpectEq("You admire Frank.\n", Player->caughtMessage());
    ExpectEq("Bob admires Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("agree -t frank"));
    ExpectEq("You agree with Frank.\n", Player->caughtMessage());
    ExpectEq("Bob agrees with Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("agrin -t frank"));
    ExpectEq("You grin at Frank like an ass.\n", Player->caughtMessage());
    ExpectEq("Bob grins at Frank like an ass.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("aha -t frank"));
    ExpectEq("You go 'Aha!' at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob goes 'Aha!' at Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("ahh -t frank"));
    ExpectEq("You go AHHH at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob goes AHHH at Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("amorous -t frank"));
    ExpectEq("You feel amorous toward Frank.\n", Player->caughtMessage());
    ExpectEq("Bob feels amorous toward Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("annoy -t frank"));
    ExpectEq("You are annoying Frank.\n", Player->caughtMessage());
    ExpectEq("Bob is annoying Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("apologize -t frank"));
    ExpectEq("You apologize to Frank.\n", Player->caughtMessage());
    ExpectEq("Bob apologizes to Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("applaud -t frank"));
    ExpectEq("You give a round of applause to Frank.\n", Player->caughtMessage());
    ExpectEq("Bob gives a round of applause to Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("ayt -t frank"));
    ExpectEq("You wave your hand back and forth in front of Frank and say, 'Are you there?'\n", Player->caughtMessage());
    ExpectEq("Bob waves his hand back and forth in front of Frank and says, 'Are you there?'\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("backhand -t frank"));
    ExpectEq("You backhand Frank.\n", Player->caughtMessage());
    ExpectEq("Bob backhands Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("baha -t frank"));
    ExpectEq("You go BAHAHAHA at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob goes BAHAHAHA at Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("bark -t frank"));
    ExpectEq("You bark like a dog at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob barks like a dog at Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("breakdance -t frank"));
    ExpectEq("You breakdance like a madman around Frank.\n", Player->caughtMessage());
    ExpectEq("Bob breakdances like a madman around Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("beep -t frank"));
    ExpectEq("You beep Frank on the nose.\n", Player->caughtMessage());
    ExpectEq("Bob beeps Frank on the nose.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("beg -t frank"));
    ExpectEq("You beg like a dog at Frank.\n", Player->caughtMessage());
    ExpectEq("Bob begs like a dog at Frank.\n", Target->caughtMessage());

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

    ExpectTrue(Player->executeCommand("boo -t frank"));
    ExpectEq("You snarl behind Frank scaring the $%!@ out of him!\n", Player->caughtMessage());
    ExpectEq("Bob snarls behind Frank scaring the $%!@ out of him!\n", Target->caughtMessage());

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

/////////////////////////////////////////////////////////////////////////////
void GooDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("goo"));
    ExpectEq("You goo.\n", Player->caughtMessage());
    ExpectEq("Bob gooes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("goo -a ineptly -t earl"));
    ExpectEq("You ineptly goo at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gooes at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gooes at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GooseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("goose"));
    ExpectEq("You goose yourself!\n", Player->caughtMessage());
    ExpectEq("Bob gooses himself!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("goose -a ineptly -t earl"));
    ExpectEq("You ineptly goose Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gooses you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gooses Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrabDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grab"));
    ExpectEq("You grab at nothing in particular.\n", Player->caughtMessage());
    ExpectEq("Bob grabs at nothing in particular.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grab -a ineptly -t earl"));
    ExpectEq("You ineptly grab Earl by the arm.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grabs you by the arm.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grabs Earl by the arm.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrimaceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grimace"));
    ExpectEq("You grimace.\n", Player->caughtMessage());
    ExpectEq("Bob grimaces.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grimace -a ineptly -t earl"));
    ExpectEq("You ineptly grimace at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grimaces at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grimaces at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grin"));
    ExpectEq("You grin.\n", Player->caughtMessage());
    ExpectEq("Bob grins.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grin -a ineptly -t earl"));
    ExpectEq("You ineptly grin at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grins at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grins at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GroanDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("groan"));
    ExpectEq("You groan loudly.\n", Player->caughtMessage());
    ExpectEq("Bob groans loudly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("groan -a raucously -t earl"));
    ExpectEq("You groan raucously at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob groans raucously at you.\n", Target->caughtMessage());
    ExpectEq("Bob groans raucously at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GropeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grope"));
    ExpectEq("You grope yourself.\n", Player->caughtMessage());
    ExpectEq("Bob gropes himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grope -a ineptly -t earl"));
    ExpectEq("You ineptly grope Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gropes you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gropes Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrovelDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grovel"));
    ExpectEq("You grovel shamelessly.\n", Player->caughtMessage());
    ExpectEq("Bob grovels shamelessly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grovel -a ineptly -t earl"));
    ExpectEq("You grovel ineptly before Earl.\n", Player->caughtMessage());
    ExpectEq("Bob grovels ineptly before you.\n", Target->caughtMessage());
    ExpectEq("Bob grovels ineptly before Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrowlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("growl"));
    ExpectEq("You growl.\n", Player->caughtMessage());
    ExpectEq("Bob growls.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("growl -a ineptly -t earl"));
    ExpectEq("You ineptly growl at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly growls at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly growls at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrumbleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("grumble"));
    ExpectEq("You grumble.\n", Player->caughtMessage());
    ExpectEq("Bob grumbles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("grumble -a ineptly -t earl"));
    ExpectEq("You ineptly grumble at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly grumbles at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly grumbles at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GuffawDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("guffaw"));
    ExpectEq("You guffaw madly.\n", Player->caughtMessage());
    ExpectEq("Bob guffaws madly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("guffaw -a loudly -t earl"));
    ExpectEq("You guffaw loudly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob guffaws loudly at you.\n", Target->caughtMessage());
    ExpectEq("Bob guffaws loudly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HairDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hair"));
    ExpectEq("You pull out your hair in frustration.\n", Player->caughtMessage());
    ExpectEq("Bob pulls out his hair in frustration.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hair -a languidly -t earl"));
    ExpectEq("You pull out your hair languidly.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HandkissDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("handkiss"));
    ExpectEq("You gently take a dismembered hand and kiss it lightly.\n", Player->caughtMessage());
    ExpectEq("Bob gently takes a dismembered hand and kisses it lightly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("handkiss -a ineptly -t earl"));
    ExpectEq("You ineptly take Earl's hand and kiss it lightly.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly takes your hand and kisses it lightly.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly takes Earl's hand and kisses it lightly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HarumphDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("harumph"));
    ExpectEq("You harumph indignantly.\n", Player->caughtMessage());
    ExpectEq("Bob harumphs indignantly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("harumph -a angrily -t earl"));
    ExpectEq("You harumph at Earl angrily.\n", Player->caughtMessage());
    ExpectEq("Bob harumphs at you angrily.\n", Target->caughtMessage());
    ExpectEq("Bob harumphs at Earl angrily.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HeeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hee"));
    ExpectEq("You go `HEE!!'.\n", Player->caughtMessage());
    ExpectEq("Bob goes `HEE!!'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hee -a ineptly -t earl"));
    ExpectEq("You ineptly go `HEE!!' at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes `HEE!!' at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes `HEE!!' at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HehDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("heh"));
    ExpectEq("You grin and go, `Heh heh heh.'\n", Player->caughtMessage());
    ExpectEq("Bob grins and goes, `Heh heh heh.'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("heh -a knowingly -t earl"));
    ExpectEq("You grin knowingly at Earl and go, `Heh heh heh.'\n", Player->caughtMessage());
    ExpectEq("Bob grins knowingly at you and goes, `Heh heh heh.'\n", Target->caughtMessage());
    ExpectEq("Bob grins knowingly at Earl and goes, `Heh heh heh.'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void Hi5DisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hi5"));
    ExpectEq("You give yourself a Hi-5!\n", Player->caughtMessage());
    ExpectEq("Bob gives himself a Hi-5!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hi5 -a ineptly -t earl"));
    ExpectEq("You ineptly give Earl a Hi-5!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gives you a Hi-5!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gives Earl a Hi-5!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HiccupDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hiccup"));
    ExpectEq("You hiccup.\n", Player->caughtMessage());
    ExpectEq("Bob hiccups.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hiccup -a ineptly -t earl"));
    ExpectEq("You ineptly hiccup at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hiccups at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hiccups at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HmmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hmm"));
    ExpectEq("You go hmmm.\n", Player->caughtMessage());
    ExpectEq("Bob goes hmmm.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hmm -a ineptly -t earl"));
    ExpectEq("You ineptly go hmmm at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes hmmm at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes hmmm at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HoldDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hold"));
    ExpectEq("You hold a stuffed ogre doll closely.\n", Player->caughtMessage());
    ExpectEq("Bob holds a stuffed ogre doll closely.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hold -a awkwardly -t earl"));
    ExpectEq("You hold Earl awkwardly.\n", Player->caughtMessage());
    ExpectEq("Bob holds you awkwardly.\n", Target->caughtMessage());
    ExpectEq("Bob holds Earl awkwardly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HopDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hop"));
    ExpectEq("You hop around.\n", Player->caughtMessage());
    ExpectEq("Bob hops around.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hop -a ineptly -t earl"));
    ExpectEq("You hop ineptly.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HowlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("howl"));
    ExpectEq("You howl in agony.\n", Player->caughtMessage());
    ExpectEq("Bob howls in agony.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("howl -a creepily -t earl"));
    ExpectEq("You howl creepily at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob howls creepily at you.\n", Target->caughtMessage());
    ExpectEq("Bob howls creepily at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HrmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hrm"));
    ExpectEq("You hrm.\n", Player->caughtMessage());
    ExpectEq("Bob hrms.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hrm -a ineptly -t earl"));
    ExpectEq("You ineptly hrm at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly hrms at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly hrms at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HugDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("hug"));
    ExpectEq("You hug a stuffed ogre doll affectionately.\n", Player->caughtMessage());
    ExpectEq("Bob hugs a stuffed ogre doll affectionately.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("hug -a tenderly -t earl"));
    ExpectEq("You hug Earl tenderly.\n", Player->caughtMessage());
    ExpectEq("Bob hugs you tenderly.\n", Target->caughtMessage());
    ExpectEq("Bob hugs Earl tenderly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void IgnoreDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ignore"));
    ExpectEq("You ignore the screams of the fallen.\n", Player->caughtMessage());
    ExpectEq("Bob ignores the screams of the fallen.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ignore -a ineptly -t earl"));
    ExpectEq("You ineptly ignore Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ignores you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ignores Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InsultDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("insult"));
    ExpectEq("You mutter something slanderous about horses in physically improbable acts.\n", Player->caughtMessage());
    ExpectEq("Bob mutters something slanderous about horses in physically improbable acts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("insult -a ineptly -t earl"));
    ExpectEq("You ineptly mutter something slanderous about Earl and horses in physically\nimprobable acts.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly mutters something slanderous about you and horses in physically\nimprobable acts.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly mutters something slanderous about Earl and horses in physically\nimprobable acts.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void JumpDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("jump"));
    ExpectEq("You jump up and down.\n", Player->caughtMessage());
    ExpectEq("Bob jumps up and down.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("jump -a ineptly -t earl"));
    ExpectEq("You jump ineptly on Earl.\n", Player->caughtMessage());
    ExpectEq("Bob jumps ineptly on you.\n", Target->caughtMessage());
    ExpectEq("Bob jumps ineptly on Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KickDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("kick"));
    ExpectEq("You kick an invisible, deceased mime.\n", Player->caughtMessage());
    ExpectEq("Bob kicks an invisible, deceased mime.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("kick -a ineptly -t earl"));
    ExpectEq("You ineptly kick Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly kicks you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly kicks Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KissDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("kiss"));
    ExpectEq("You kiss yourself affectionately.\n", Player->caughtMessage());
    ExpectEq("Bob kisses himself affectionately.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("kiss -a languidly -t earl"));
    ExpectEq("You kiss Earl languidly.\n", Player->caughtMessage());
    ExpectEq("Bob kisses you languidly.\n", Target->caughtMessage());
    ExpectEq("Bob kisses Earl languidly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LaughDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("laugh"));
    ExpectEq("You fall down laughing.\n", Player->caughtMessage());
    ExpectEq("Bob falls down laughing.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("laugh -a raucously -t earl"));
    ExpectEq("You fall down raucously laughing at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob falls down raucously laughing at you.\n", Target->caughtMessage());
    ExpectEq("Bob falls down raucously laughing at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LdDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ld"));
    ExpectEq("You get clobbered by linkdeath - again and again.\n", Player->caughtMessage());
    ExpectEq("Bob gets clobbered by linkdeath - again and again.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ld -a annoyingly -t earl"));
    ExpectEq("You annoyingly get clobbered by linkdeath - again and again.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LickDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("lick"));
    ExpectEq("You lick yourself!\n", Player->caughtMessage());
    ExpectEq("Bob licks himself!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("lick -a ineptly -t earl"));
    ExpectEq("You ineptly lick Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly licks you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly licks Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LolDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("lol"));
    ExpectEq("You laugh out loud.\n", Player->caughtMessage());
    ExpectEq("Bob laughs out loud.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("lol -a ineptly -t earl"));
    ExpectEq("You ineptly laugh out loud at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly laughs out loud at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly laughs out loud at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LoveDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("love"));
    ExpectEq("You whisper sweet words of love to the sky.\n", Player->caughtMessage());
    ExpectEq("Bob whispers sweet words of love to the sky.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("love -a ineptly -t earl"));
    ExpectEq("You ineptly whisper sweet words of love to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly whispers sweet words of love to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly whispers sweet words of love to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MehDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("meh"));
    ExpectEq("You go `meh'.\n", Player->caughtMessage());
    ExpectEq("Bob goes `meh'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("meh -a ineptly -t earl"));
    ExpectEq("You ineptly go `meh' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes `meh' to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes `meh' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MgrinDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mgrin"));
    ExpectEq("You grin mischievously.\n", Player->caughtMessage());
    ExpectEq("Bob grins mischievously.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mgrin -a sardonically -t earl"));
    ExpectEq("You grin sardonically at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob grins sardonically at you.\n", Target->caughtMessage());
    ExpectEq("Bob grins sardonically at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoanDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("moan"));
    ExpectEq("You start moaning.\n", Player->caughtMessage());
    ExpectEq("Bob starts moaning.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("moan -a ridiculously -t earl"));
    ExpectEq("You start ridiculously moaning to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob starts ridiculously moaning to you.\n", Target->caughtMessage());
    ExpectEq("Bob starts ridiculously moaning to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MockDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mock"));
    ExpectEq("You mock the accursed inanimate objects outrageously.\n", Player->caughtMessage());
    ExpectEq("Bob mocks the accursed inanimate objects outrageously.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mock -a relentlessly -t earl"));
    ExpectEq("You mock Earl relentlessly.\n", Player->caughtMessage());
    ExpectEq("Bob mocks you relentlessly.\n", Target->caughtMessage());
    ExpectEq("Bob mocks Earl relentlessly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MstampDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("mstamp"));
    ExpectEq("You slap an official `I am a moron!' sticker on your forehead.\n", Player->caughtMessage());
    ExpectEq("Bob slaps an official `I am a moron!' sticker on his forehead.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("mstamp -a ineptly -t earl"));
    ExpectEq("You ineptly slap an official `I am a moron!' sticker on Earl's forehead.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly slaps an official `I am a moron!' sticker on your forehead.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly slaps an official `I am a moron!' sticker on Earl's forehead.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NibbleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nibble"));
    ExpectEq("You nibble a dead rabbit's ear.\n", Player->caughtMessage());
    ExpectEq("Bob nibbles a dead rabbit's ear.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nibble -a hungrily -t earl"));
    ExpectEq("You hungrily nibble Earl's ear.\n", Player->caughtMessage());
    ExpectEq("Bob hungrily nibbles your ear.\n", Target->caughtMessage());
    ExpectEq("Bob hungrily nibbles Earl's ear.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NodDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nod"));
    ExpectEq("You nod.\n", Player->caughtMessage());
    ExpectEq("Bob nods.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nod -a agreeably -t earl"));
    ExpectEq("You agreeably nod at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob agreeably nods at you.\n", Target->caughtMessage());
    ExpectEq("Bob agreeably nods at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NogDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nog"));
    ExpectEq("You nog.\n", Player->caughtMessage());
    ExpectEq("Bob nogs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nog -a ineptly -t earl"));
    ExpectEq("You ineptly nog at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nogs at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nogs at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoogieDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("noogie"));
    ExpectEq("You give yourself a noogie.\n", Player->caughtMessage());
    ExpectEq("Bob gives himself a noogie.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("noogie -a ineptly -t earl"));
    ExpectEq("You ineptly give Earl a noogie.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly gives you a noogie.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly gives Earl a noogie.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NudgeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("nudge"));
    ExpectEq("You nudge a speck of dust.\n", Player->caughtMessage());
    ExpectEq("Bob nudges a speck of dust.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("nudge -a ineptly -t earl"));
    ExpectEq("You ineptly nudge Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly nudges you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly nudges Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OuchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ouch"));
    ExpectEq("You exclaim, `Ouch!'\n", Player->caughtMessage());
    ExpectEq("Bob exclaims, `Ouch!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ouch -a tearfully -t earl"));
    ExpectEq("You tearfully exclaim, `Ouch!'\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PaceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pace"));
    ExpectEq("You pace around the area.\n", Player->caughtMessage());
    ExpectEq("Bob paces around the area.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pace -a ineptly -t earl"));
    ExpectEq("You ineptly pace around Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly paces around you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly paces around Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PanicDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("panic"));
    ExpectEq("You panic.\n", Player->caughtMessage());
    ExpectEq("Bob panics.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("panic -a ineptly -t earl"));
    ExpectEq("You ineptly panic.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PatDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pat"));
    ExpectEq("You pat yourself on the head.\n", Player->caughtMessage());
    ExpectEq("Bob pats himself on the head.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pat -a ineptly -t earl"));
    ExpectEq("You ineptly pat Earl on the head.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pats you on the head.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pats Earl on the head.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PeerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("peer"));
    ExpectEq("You peer upward quizically.\n", Player->caughtMessage());
    ExpectEq("Bob peers upward quizically.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("peer -a silently -t earl"));
    ExpectEq("You peer at Earl silently.\n", Player->caughtMessage());
    ExpectEq("Bob peers at you silently.\n", Target->caughtMessage());
    ExpectEq("Bob peers at Earl silently.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PfftDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pfft"));
    ExpectEq("You go PFFT!\n", Player->caughtMessage());
    ExpectEq("Bob goes PFFT!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pfft -a ineptly -t earl"));
    ExpectEq("You ineptly go PFFT at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes PFFT at you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes PFFT at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PinchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pinch"));
    ExpectEq("You pinch yourself.\n", Player->caughtMessage());
    ExpectEq("Bob pinches himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pinch -a ineptly -t earl"));
    ExpectEq("You ineptly pinch Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pinches you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pinches Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PizzaDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pizza"));
    ExpectEq("You pizza hungrily.\n", Player->caughtMessage());
    ExpectEq("Bob pizzas hungrily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pizza -a droolingly -t earl"));
    ExpectEq("You pizza at Earl droolingly.\n", Player->caughtMessage());
    ExpectEq("Bob pizzas at you droolingly.\n", Target->caughtMessage());
    ExpectEq("Bob pizzas at Earl droolingly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PleaseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("please"));
    ExpectEq("You make puppy dog eyes and say, `Please?'\n", Player->caughtMessage());
    ExpectEq("Bob makes puppy dog eyes and says, `Please?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("please -a ineptly -t earl"));
    ExpectEq("You make puppy dog eyes at Earl and ineptly say, `Please?'\n", Player->caughtMessage());
    ExpectEq("Bob makes puppy dog eyes at you and ineptly says, `Please?'\n", Target->caughtMessage());
    ExpectEq("Bob makes puppy dog eyes at Earl and ineptly says, `Please?'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PointDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("point"));
    ExpectEq("You point upward.\n", Player->caughtMessage());
    ExpectEq("Bob points upward.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("point -a ineptly -t earl"));
    ExpectEq("You ineptly point at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly points at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly points at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PokeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("poke"));
    ExpectEq("You poke an invisible dragon in the ribs.\n", Player->caughtMessage());
    ExpectEq("Bob pokes an invisible dragon in the ribs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("poke -a violently -t earl"));
    ExpectEq("You violently poke Earl in the ribs.\n", Player->caughtMessage());
    ExpectEq("Bob violently pokes you in the ribs.\n", Target->caughtMessage());
    ExpectEq("Bob violently pokes Earl in the ribs.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PonderDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ponder"));
    ExpectEq("You ponder the situation.\n", Player->caughtMessage());
    ExpectEq("Bob ponders the situation.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ponder -a ineptly -t earl"));
    ExpectEq("You ineptly ponder Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly ponders you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly ponders Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PounceDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pounce"));
    ExpectEq("You pounce viciously toward an imaginary target, missing spectacularly.\n", Player->caughtMessage());
    ExpectEq("Bob pounces viciously toward an imaginary target, missing spectacularly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pounce -a intrepidly -t earl"));
    ExpectEq("You pounce intrepidly on Earl.\n", Player->caughtMessage());
    ExpectEq("Bob pounces intrepidly on you.\n", Target->caughtMessage());
    ExpectEq("Bob pounces intrepidly on Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PoutDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("pout"));
    ExpectEq("You pout.\n", Player->caughtMessage());
    ExpectEq("Bob pouts.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("pout -a pathetically -t earl"));
    ExpectEq("You pathetically pout at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob pathetically pouts at you.\n", Target->caughtMessage());
    ExpectEq("Bob pathetically pouts at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PukeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("puke"));
    ExpectEq("You puke all over the ground.\n", Player->caughtMessage());
    ExpectEq("Bob pukes all over the ground.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("puke -a ineptly -t earl"));
    ExpectEq("You ineptly puke all over Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly pukes all over you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly pukes all over Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PunchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("punch"));
    ExpectEq("You punch at unseen foes!\n", Player->caughtMessage());
    ExpectEq("Bob punches at unseen foes!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("punch -a artfully -t earl"));
    ExpectEq("You artfully punch Earl!\n", Player->caughtMessage());
    ExpectEq("Bob artfully punches you!\n", Target->caughtMessage());
    ExpectEq("Bob artfully punches Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PurrDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("purr"));
    ExpectEq("You purr contentedly.\n", Player->caughtMessage());
    ExpectEq("Bob purrs contentedly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("purr -a loudly -t earl"));
    ExpectEq("You purr loudly to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob purrs loudly to you.\n", Target->caughtMessage());
    ExpectEq("Bob purrs loudly to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PuzzleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("puzzle"));
    ExpectEq("You look puzzled.\n", Player->caughtMessage());
    ExpectEq("Bob looks puzzled.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("puzzle -a ineptly -t earl"));
    ExpectEq("You look puzzled by Earl.\n", Player->caughtMessage());
    ExpectEq("Bob looks puzzled by you.\n", Target->caughtMessage());
    ExpectEq("Bob looks puzzled by Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RaiseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("raise"));
    ExpectEq("You raise an eyebrow.\n", Player->caughtMessage());
    ExpectEq("Bob raises an eyebrow.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("raise -a ineptly -t earl"));
    ExpectEq("You ineptly raise an eyebrow at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly raises an eyebrow at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly raises an eyebrow at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RecoilDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("recoil"));
    ExpectEq("You recoil in horror.\n", Player->caughtMessage());
    ExpectEq("Bob recoils in horror.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("recoil -a fearfully -t earl"));
    ExpectEq("You fearfully recoil from Earl.\n", Player->caughtMessage());
    ExpectEq("Bob fearfully recoils from you.\n", Target->caughtMessage());
    ExpectEq("Bob fearfully recoils from Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RoflDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("rofl"));
    ExpectEq("You roll around on the floor laughing.\n", Player->caughtMessage());
    ExpectEq("Bob rolls around on the floor laughing.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("rofl -a hysterically -t earl"));
    ExpectEq("You roll around on the floor hysterically laughing at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob rolls around on the floor hysterically laughing at you.\n", Target->caughtMessage());
    ExpectEq("Bob rolls around on the floor hysterically laughing at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RollDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("roll"));
    ExpectEq("You roll your eyes.\n", Player->caughtMessage());
    ExpectEq("Bob rolls his eyes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("roll -a ineptly -t earl"));
    ExpectEq("You ineptly roll your eyes at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly rolls his eyes at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly rolls his eyes at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RuffleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("ruffle"));
    ExpectEq("You ruffle your hair playfully.\n", Player->caughtMessage());
    ExpectEq("Bob ruffles his hair playfully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("ruffle -a seductively -t earl"));
    ExpectEq("You ruffle Earl's hair seductively.\n", Player->caughtMessage());
    ExpectEq("Bob ruffles your hair seductively.\n", Target->caughtMessage());
    ExpectEq("Bob ruffles Earl's hair seductively.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScratchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("scratch"));
    ExpectEq("You scratch your head.\n", Player->caughtMessage());
    ExpectEq("Bob scratches his head.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("scratch -a ineptly -t earl"));
    ExpectEq("You ineptly scratch Earl's head.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly scratches your head.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly scratches Earl's head.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScreamDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("scream"));
    ExpectEq("You scream loudly!\n", Player->caughtMessage());
    ExpectEq("Bob screams loudly!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("scream -a mutely -t earl"));
    ExpectEq("You scream mutely at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob screams mutely at you!\n", Target->caughtMessage());
    ExpectEq("Bob screams mutely at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShakeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shake"));
    ExpectEq("You shake your head.\n", Player->caughtMessage());
    ExpectEq("Bob shakes his head.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shake -a ineptly -t earl"));
    ExpectEq("You ineptly shake Earl's hand.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shakes your hand.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shakes Earl's hand.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShhDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shh"));
    ExpectEq("You try to silence everyone... SHHHHHH!\n", Player->caughtMessage());
    ExpectEq("Bob tries to silence everyone... SHHHHHH!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shh -a ineptly -t earl"));
    ExpectEq("You ineptly try to silence Earl... SHHHHHH!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tries to silence you... SHHHHHH!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tries to silence Earl... SHHHHHH!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShivDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shiv"));
    ExpectEq("You stab yourself with a fake shiv.\n", Player->caughtMessage());
    ExpectEq("Bob stabs himself with a fake shiv.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shiv -a ineptly -t earl"));
    ExpectEq("You ineptly stab Earl with a fake shiv.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly stabs you with a fake shiv.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly stabs Earl with a fake shiv.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShiverDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shiver"));
    ExpectEq("You shiver.\n", Player->caughtMessage());
    ExpectEq("Bob shivers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shiver -a ineptly -t earl"));
    ExpectEq("You ineptly shiver at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shivers at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shivers at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShiversDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shivers"));
    ExpectEq("You shiver from the cold.\n", Player->caughtMessage());
    ExpectEq("Bob shivers from the cold.\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShrugDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shrug"));
    ExpectEq("You shrug helplessly.\n", Player->caughtMessage());
    ExpectEq("Bob shrugs helplessly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shrug -a comically -t earl"));
    ExpectEq("You shrug at Earl comically.\n", Player->caughtMessage());
    ExpectEq("Bob shrugs at you comically.\n", Target->caughtMessage());
    ExpectEq("Bob shrugs at Earl comically.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShudderDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("shudder"));
    ExpectEq("You shudder.\n", Player->caughtMessage());
    ExpectEq("Bob shudders.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("shudder -a ineptly -t earl"));
    ExpectEq("You ineptly shudder at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly shudders at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly shudders at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SighDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sigh"));
    ExpectEq("You sigh deeply.\n", Player->caughtMessage());
    ExpectEq("Bob sighs deeply.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sigh -a disgustedly -t earl"));
    ExpectEq("You sigh disgustedly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob sighs disgustedly at you.\n", Target->caughtMessage());
    ExpectEq("Bob sighs disgustedly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SlapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("slap"));
    ExpectEq("You slap yourself.\n", Player->caughtMessage());
    ExpectEq("Bob slaps himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("slap -a ineptly -t earl"));
    ExpectEq("You ineptly slap Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly slaps you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly slaps Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmileDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smile"));
    ExpectEq("You smile.\n", Player->caughtMessage());
    ExpectEq("Bob smiles.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smile -a happily -t earl"));
    ExpectEq("You happily smile at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob happily smiles at you.\n", Target->caughtMessage());
    ExpectEq("Bob happily smiles at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmirkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smirk"));
    ExpectEq("You smirk.\n", Player->caughtMessage());
    ExpectEq("Bob smirks.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smirk -a ineptly -t earl"));
    ExpectEq("You ineptly smirk at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly smirks at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly smirks at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SmoochDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("smooch"));
    ExpectEq("You smooch a passing harpy with reckless abandon!\n", Player->caughtMessage());
    ExpectEq("Bob smooches a passing harpy with reckless abandon!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("smooch -a ineptly -t earl"));
    ExpectEq("You ineptly smooch Earl with reckless abandon!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly smooches you with reckless abandon!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly smooches Earl with reckless abandon!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snap"));
    ExpectEq("You snap your fingers.\n", Player->caughtMessage());
    ExpectEq("Bob snaps his fingers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snap -a ineptly -t earl"));
    ExpectEq("You ineptly snap your fingers at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snaps his fingers at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snaps his fingers at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnarlDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snarl"));
    ExpectEq("You snarl angrily.\n", Player->caughtMessage());
    ExpectEq("Bob snarls angrily.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snarl -a seductively -t earl"));
    ExpectEq("You snarl seductively at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob snarls seductively at you.\n", Target->caughtMessage());
    ExpectEq("Bob snarls seductively at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SneezeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sneeze"));
    ExpectEq("You sneeze.\n", Player->caughtMessage());
    ExpectEq("Bob sneezes.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sneeze -a ineptly -t earl"));
    ExpectEq("You ineptly sneeze at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sneezes at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sneezes at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnickerDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snicker"));
    ExpectEq("You snicker.\n", Player->caughtMessage());
    ExpectEq("Bob snickers.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snicker -a ineptly -t earl"));
    ExpectEq("You ineptly snicker at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly snickers at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly snickers at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SniffDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sniff"));
    ExpectEq("You sniff.\n", Player->caughtMessage());
    ExpectEq("Bob sniffs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sniff -a ineptly -t earl"));
    ExpectEq("You ineptly sniff Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sniffs you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sniffs Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnoreDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snore"));
    ExpectEq("You snore loudly.\n", Player->caughtMessage());
    ExpectEq("Bob snores loudly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snore -a unconvincingly -t earl"));
    ExpectEq("You snore unconvincingly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob snores unconvincingly at you.\n", Target->caughtMessage());
    ExpectEq("Bob snores unconvincingly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnortDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snort"));
    ExpectEq("You snort!\n", Player->caughtMessage());
    ExpectEq("Bob snorts!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snort -a salaciously -t earl"));
    ExpectEq("You salaciously snort at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob salaciously snorts at you!\n", Target->caughtMessage());
    ExpectEq("Bob salaciously snorts at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SnuggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("snuggle"));
    ExpectEq("You snuggle with a plush dragon toy.\n", Player->caughtMessage());
    ExpectEq("Bob snuggles with a plush dragon toy.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("snuggle -a quietly -t earl"));
    ExpectEq("You quietly snuggle up to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob quietly snuggles up to you.\n", Target->caughtMessage());
    ExpectEq("Bob quietly snuggles up to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SobDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sob"));
    ExpectEq("You sob uncontrollably.\n", Player->caughtMessage());
    ExpectEq("Bob sobs uncontrollably.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sob -a inconsolably -t earl"));
    ExpectEq("You sob inconsolably to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob sobs inconsolably to you.\n", Target->caughtMessage());
    ExpectEq("Bob sobs inconsolably to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpankDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("spank"));
    ExpectEq("You spank yourself!\n", Player->caughtMessage());
    ExpectEq("Bob spanks himself!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("spank -a ineptly -t earl"));
    ExpectEq("You ineptly spank Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly spanks you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly spanks Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SpitDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("spit"));
    ExpectEq("You spit on the ground.\n", Player->caughtMessage());
    ExpectEq("Bob spits on the ground.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("spit -a ineptly -t earl"));
    ExpectEq("You ineptly spit on Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly spits on you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly spits on Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SqueezeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("squeeze"));
    ExpectEq("You squeeze yourself fondly.\n", Player->caughtMessage());
    ExpectEq("Bob squeezes himself fondly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("squeeze -a ineptly -t earl"));
    ExpectEq("You squeeze Earl ineptly.\n", Player->caughtMessage());
    ExpectEq("Bob squeezes you ineptly.\n", Target->caughtMessage());
    ExpectEq("Bob squeezes Earl ineptly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SquirmDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("squirm"));
    ExpectEq("You squirm about on the floor.\n", Player->caughtMessage());
    ExpectEq("Bob squirms about on the floor.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("squirm -a ineptly -t earl"));
    ExpectEq("You ineptly squirm about on the floor.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StareDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stare"));
    ExpectEq("You stare.\n", Player->caughtMessage());
    ExpectEq("Bob stares.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stare -a ineptly -t earl"));
    ExpectEq("You ineptly stare deep into Earl's eyes.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly stares deep into your eyes.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly stares deep into Earl's eyes.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StartDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("start"));
    ExpectEq("You start in surprise.\n", Player->caughtMessage());
    ExpectEq("Bob starts in surprise.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("start -a guiltily -t earl"));
    ExpectEq("You start guiltily.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SeetheDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("seethe"));
    ExpectEq("You seethe in silence.\n", Player->caughtMessage());
    ExpectEq("Bob seethes in silence.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("seethe -a silently -t earl"));
    ExpectEq("You silently seethe at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob silently seethes at you.\n", Target->caughtMessage());
    ExpectEq("Bob silently seethes at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StompDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stomp"));
    ExpectEq("You stomp your foot!\n", Player->caughtMessage());
    ExpectEq("Bob stomps his foot!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stomp -a angrily -t earl"));
    ExpectEq("You angrily stomp your foot!\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StretchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("stretch"));
    ExpectEq("You stretch sleepily and yawn.\n", Player->caughtMessage());
    ExpectEq("Bob stretches sleepily and yawns.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("stretch -a languidly -t earl"));
    ExpectEq("You stretch languidly and yawn.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void StrutDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("strut"));
    ExpectEq("You strut proudly.\n", Player->caughtMessage());
    ExpectEq("Bob struts proudly.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("strut -a ineptly -t earl"));
    ExpectEq("You strut ineptly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob struts ineptly at you.\n", Target->caughtMessage());
    ExpectEq("Bob struts ineptly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SulkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("sulk"));
    ExpectEq("You sulk in the corner.\n", Player->caughtMessage());
    ExpectEq("Bob sulks in the corner.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("sulk -a ineptly -t earl"));
    ExpectEq("You ineptly sulk to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly sulks to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly sulks to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TackleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tackle"));
    ExpectEq("You tackle an invisible pigmy to the ground.\n", Player->caughtMessage());
    ExpectEq("Bob tackles an invisible pigmy to the ground.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tackle -a ineptly -t earl"));
    ExpectEq("You ineptly tackle Earl to the ground.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly tackles you to the ground.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly tackles Earl to the ground.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TahdahDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tahdah"));
    ExpectEq("You go `Tah dah'.\n", Player->caughtMessage());
    ExpectEq("Bob goes `Tah dah'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tahdah -a ineptly -t earl"));
    ExpectEq("You ineptly go `Tah dah' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes `Tah dah' to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes `Tah dah' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tap"));
    ExpectEq("You tap your foot.\n", Player->caughtMessage());
    ExpectEq("Bob taps his foot.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tap -a ineptly -t earl"));
    ExpectEq("You ineptly tap Earl's shoulder.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly taps your shoulder.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly taps Earl's shoulder.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TauntDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("taunt"));
    ExpectEq("You taunt the world's inanimate objects.\n", Player->caughtMessage());
    ExpectEq("Bob taunts the world's inanimate objects.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("taunt -a ineptly -t earl"));
    ExpectEq("You ineptly taunt Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly taunts you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly taunts Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TeaseDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tease"));
    ExpectEq("You tease cabbage for, well, being cabbage.\n", Player->caughtMessage());
    ExpectEq("Bob teases cabbage for, well, being cabbage.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tease -a ineptly -t earl"));
    ExpectEq("You ineptly tease Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly teases you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly teases Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThankDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("thank"));
    ExpectEq("You thank the world for every dead mime.\n", Player->caughtMessage());
    ExpectEq("Bob thanks the world for every dead mime.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("thank -a ineptly -t earl"));
    ExpectEq("You ineptly thank Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly thanks you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly thanks Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThinkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("think"));
    ExpectEq("You think carefully.\n", Player->caughtMessage());
    ExpectEq("Bob thinks carefully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("think -a perversely -t earl"));
    ExpectEq("You think about Earl perversely.\n", Player->caughtMessage());
    ExpectEq("Bob thinks about you perversely.\n", Target->caughtMessage());
    ExpectEq("Bob thinks about Earl perversely.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThwapDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("thwap"));
    ExpectEq("You thwap yourself.\n", Player->caughtMessage());
    ExpectEq("Bob thwaps himself.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("thwap -a ineptly -t earl"));
    ExpectEq("You ineptly thwap Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly thwaps you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly thwaps Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TickleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tickle"));
    ExpectEq("You tickle yourself playfully.\n", Player->caughtMessage());
    ExpectEq("Bob tickles himself playfully.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tickle -a ineptly -t earl"));
    ExpectEq("You tickle Earl ineptly.\n", Player->caughtMessage());
    ExpectEq("Bob tickles you ineptly.\n", Target->caughtMessage());
    ExpectEq("Bob tickles Earl ineptly.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TskDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("tsk"));
    ExpectEq("You go `tsk, tsk, tsk'.\n", Player->caughtMessage());
    ExpectEq("Bob goes `tsk, tsk, tsk'.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("tsk -a ineptly -t earl"));
    ExpectEq("You ineptly go `tsk, tsk, tsk' to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes `tsk, tsk, tsk' to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes `tsk, tsk, tsk' to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwiddleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("twiddle"));
    ExpectEq("You twiddle your thumbs.\n", Player->caughtMessage());
    ExpectEq("Bob twiddles his thumbs.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("twiddle -a despondently"));
    ExpectEq("You despondently twiddle your thumbs.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwitchDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("twitch"));
    ExpectEq("You twitch your left eyelid.\n", Player->caughtMessage());
    ExpectEq("Bob twitches his left eyelid.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("twitch -a ineptly -t earl"));
    ExpectEq("You ineptly twitch your left eyelid at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly twitches his left eyelid at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly twitches his left eyelid at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WaveDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wave"));
    ExpectEq("You wave.\n", Player->caughtMessage());
    ExpectEq("Bob waves.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wave -a ineptly -t earl"));
    ExpectEq("You ineptly wave at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly waves at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly waves at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WeirdDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("weird"));
    ExpectEq("You look at nothing in particular and say, `Wierdo!'\n", Player->caughtMessage());
    ExpectEq("Bob looks at nothing in particular and says, `Wierdo!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("weird -a ineptly -t earl"));
    ExpectEq("You ineptly look at Earl and say, `Wierdo!'\n", Player->caughtMessage());
    ExpectEq("Bob ineptly looks at you and says, `Wierdo!'\n", Target->caughtMessage());
    ExpectEq("Bob ineptly looks at Earl and says, `Wierdo!'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WellDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("well"));
    ExpectEq("You place your hands on your hips and say, `Well?'\n", Player->caughtMessage());
    ExpectEq("Bob places his hands on his hips and says, `Well?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("well -a ineptly -t earl"));
    ExpectEq("Bob ineptly places his hands on his hips and says, `Well?'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WheeDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whee"));
    ExpectEq("You run around screaming, `WHEEEEEE!'\n", Player->caughtMessage());
    ExpectEq("Bob runs around screaming, `WHEEEEEE!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whee -a ineptly -t earl"));
    ExpectEq("Bob ineptly runs around screaming, `WHEEEEEE!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WhineDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whine"));
    ExpectEq("You whine.\n", Player->caughtMessage());
    ExpectEq("Bob whines.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whine -a ineptly -t earl"));
    ExpectEq("You ineptly whine at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly whines at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly whines at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WhistleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("whistle"));
    ExpectEq("You whistle appreciatively.\n", Player->caughtMessage());
    ExpectEq("Bob whistles appreciatively.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("whistle -a suggestively -t earl"));
    ExpectEq("You whistle suggestively at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob whistles suggestively at you.\n", Target->caughtMessage());
    ExpectEq("Bob whistles suggestively at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WiggleDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wiggle"));
    ExpectEq("You wiggle your bottom.\n", Player->caughtMessage());
    ExpectEq("Bob wiggles his bottom.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wiggle -a ineptly -t earl"));
    ExpectEq("You ineptly wiggle your bottom at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly wiggles his bottom at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly wiggles his bottom at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WinkDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("wink"));
    ExpectEq("You wink suggestively.\n", Player->caughtMessage());
    ExpectEq("Bob winks suggestively.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("wink -a stupidly -t earl"));
    ExpectEq("You wink stupidly at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob winks stupidly at you.\n", Target->caughtMessage());
    ExpectEq("Bob winks stupidly at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WorshipDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("worship"));
    ExpectEq("You fall to the ground and worship a dust bunny.\n", Player->caughtMessage());
    ExpectEq("Bob falls to the ground and worships a dust bunny.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("worship -a ineptly -t earl"));
    ExpectEq("You fall to the ground and ineptly worship Earl.\n", Player->caughtMessage());
    ExpectEq("Bob falls to the ground and ineptly worships you.\n", Target->caughtMessage());
    ExpectEq("Bob falls to the ground and ineptly worships Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YawnDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yawn"));
    ExpectEq("You yawn.\n", Player->caughtMessage());
    ExpectEq("Bob yawns.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yawn -a ineptly -t earl"));
    ExpectEq("You ineptly yawn at Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yawns at you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yawns at Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YayDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yay"));
    ExpectEq("You go `YAY'!\n", Player->caughtMessage());
    ExpectEq("Bob goes `YAY'!\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yay -a ineptly -t earl"));
    ExpectEq("You ineptly go `YAY' at Earl!\n", Player->caughtMessage());
    ExpectEq("Bob ineptly goes `YAY' at you!\n", Target->caughtMessage());
    ExpectEq("Bob ineptly goes `YAY' at Earl!\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YeahDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yeah"));
    ExpectEq("You raise your eyebrows and go, `Yeah?'\n", Player->caughtMessage());
    ExpectEq("Bob raises his eyebrows and goes, `Yeah?'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yeah -a ineptly -t earl"));
    ExpectEq("You ineptly raise your eyebrows at Earl and go, `Yeah?'\n", Player->caughtMessage());
    ExpectEq("Bob ineptly raises his eyebrows at you and goes, `Yeah?'\n", Target->caughtMessage());
    ExpectEq("Bob ineptly raises his eyebrows at Earl and goes, `Yeah?'\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YodelDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yodel"));
    ExpectEq("You yodel a merry tune.\n", Player->caughtMessage());
    ExpectEq("Bob yodels a merry tune.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yodel -a ineptly -t earl"));
    ExpectEq("You ineptly yodel a merry tune to Earl.\n", Player->caughtMessage());
    ExpectEq("Bob ineptly yodels a merry tune to you.\n", Target->caughtMessage());
    ExpectEq("Bob ineptly yodels a merry tune to Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void YuckDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("yuck"));
    ExpectEq("You look grossed out.\n", Player->caughtMessage());
    ExpectEq("Bob looks grossed out.\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("yuck -a completely -t earl"));
    ExpectEq("You look completely grossed out by Earl.\n", Player->caughtMessage());
    ExpectEq("Bob looks completely grossed out by you.\n", Target->caughtMessage());
    ExpectEq("Bob looks completely grossed out by Earl.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ZingDisplaysCorrectMessages()
{
    ExpectTrue(Player->executeCommand("zing"));
    ExpectEq("You hold up a finger and say, `Zing!'\n", Player->caughtMessage());
    ExpectEq("Bob holds up a finger and says, `Zing!'\n", Target->caughtMessage());

    ExpectTrue(Player->executeCommand("zing -a ineptly -t earl"));
    ExpectEq("Bob holds up a finger and ineptly says, `Zing!'\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HostileActionsTriggerRetaliation()
{
    destruct(Target);
    Target = clone_object("/lib/realizations/monster.c");
    Target->Name("earl");
    Target->Race("human");
    Target->Gender(1);

    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow->beginShadow(Target);
    move_object(Target, this_object());

    ExpectTrue(Player->executeCommand("backhand earl"));
    ExpectEq(({ "You backhand Earl.\n",
        "Earl punches you.\n" }), Player->caughtMessages());
    ExpectEq("You punch Bob.\n", Target->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlySelfTargetForCertainCommands()
{
    ExpectTrue(Player->executeCommand("french -t bob"));
    ExpectEq("Command failed: You cannot target yourself.\n", Player->caughtMessage());
    ExpectEq(0, Target->caughtMessage());
    ExpectEq(0, Bystander->caughtMessage());

    ExpectTrue(Player->executeCommand("think -a perversely -t bob"));
    ExpectEq("You think about Bob perversely.\n", Player->caughtMessage());
    ExpectEq("Bob thinks about Bob perversely.\n", Target->caughtMessage());
    ExpectEq("Bob thinks about Bob perversely.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoneColorIsSupported()
{
    Player->colorConfiguration("3-bit");
    Bystander->colorConfiguration("none");
    ExpectTrue(Player->executeCommand("burp"));
    ExpectEq("\x1b[0;36mYou burp rudely.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("Bob burps rudely.\n", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorIsSupported()
{
    Player->colorConfiguration("8-bit");
    Bystander->colorConfiguration("3-bit");
    ExpectTrue(Player->executeCommand("burp"));
    ExpectEq("\x1b[0;38;5;92mYou burp rudely.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;36mBob burps rudely.\n\x1b[0m", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorIsSupported()
{
    Player->colorConfiguration("none");
    Bystander->colorConfiguration("8-bit");
    ExpectTrue(Player->executeCommand("burp"));
    ExpectEq("You burp rudely.\n", Player->caughtMessage());
    ExpectEq("\x1b[0;38;5;92mBob burps rudely.\n\x1b[0m", Bystander->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorIsSupported()
{
    Player->colorConfiguration("24-bit");
    Bystander->colorConfiguration("24-bit");
    ExpectTrue(Player->executeCommand("burp"));
    ExpectEq("\x1b[0;38;2;180;180;190mYou burp rudely.\n\x1b[0m", Player->caughtMessage());
    ExpectEq("\x1b[0;38;2;180;180;190mBob burps rudely.\n\x1b[0m", Bystander->caughtMessage());
}
