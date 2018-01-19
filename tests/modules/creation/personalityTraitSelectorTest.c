//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void AnswerQuestionsTakeFirstChoice()
{
    while (!Selector->testTaken())
    {
        Selector->applySelection("1");
    }
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AnswerQuestionsTakeFirstChoice" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/personalityTraitSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->Race("human");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrect()
{
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYou have been invited to attend a grand ball. All of the nobility\n"
        "will be there, though you do not know any of them. You are expected to\n"
        "mingle with them. Does this[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mExcite and energize you. This is, after all, your element and you\n"
        "\t      love meeting new people.\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mFill you with a sense of dread. People suck and you really would\n"
        "\t      rather stay home doing something far more interesting\n"
        "\t      like rearranging your sock drawer. The thought of\n"
        "\t      listening to the bemoanings of all these self-absorbed\n"
        "\t      assholes you'll never see again just doesn't excite you.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SecondQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYour instructor likes to torment his students with inane activites. Today,\n"
        "he has assigned the task of adding all numbers from 1 to 1000. Do you[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mGet on with it. If you hurry up and work through the problem as\n"
        "\t      convention dictates, it shouldn't take too long ere you're done\n"
        "\t      and able to move on to more enjoyable activities.\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mReject convention. If you think about the problem for a while,\n"
        "\t      you may well come up with a better way of solving the problem. Of\n"
        "\t      course, maybe you won't and you could end up wasting time\n"
        "\t      needlessly.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThirdQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYou have gone to a village meeting wherein you are discussing two projects\n"
        "that are competing for the same resources: the building of a new well for\n"
        "irrigation or erecting a statue of Sir Whatshisname Of Whocares. Most there\n"
        "seem inclined to build the statue - he was the village founder, after all -\n"
        "but you think the well is the only sensible idea. Do you[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mThoroughly discuss all of the pros and cons of both projects and\n"
        "\t      clearly detail why the well is the only logical choice.\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSeek to understand why the others want the statue and work toward\n"
        "\t      the consensus opinion in the end.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FourthQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mAs the leader of an expeditionary force, you have come across an enemy\n"
        "encampment. Through your reconnaissance, you have been able to clearly\n"
        "determine that they are planning to lead a campaign to loot and pillage\n"
        "your leige's lands. Do you[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mMeticulously and methodically organize your plan of attack. You\n"
        "\t      will only get one chance, so this had best be perfect.\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mPrepare for the attack with those resources you have on hand. The\n"
        "\t      plan may not be perfect, but it is not rigid and you trust in\n"
        "\t      yourself to adapt as new information comes your way.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FifthQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYou have been hired by the local lord to track down and apprehend a war\n"
        "criminal. In time, you find the man - one of your old comrades-in-arms. As you\n"
        "are in the process of taking him back for judgement, you discover that his\n"
        "'crimes' involved turning on his lord when ordered to raze a town and butcher\n"
        "its citizens whose only crime was refusing to surrender their harvest to this\n"
        "lord's armies. He and four others defected and protected the townsfolk. In the\n"
        "ensuing melee, he was victorious though his companions all perished. Do you[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mHonor your contract and bring the man to justice knowing that he\n"
        "\t      faces executioner for acting with compassion and honor in\n"
        "\t      protecting innocents.\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mFree him knowing that, at best, your quest will fail and at worst,\n"
        "\t      your duplicity will be discovered.\n[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mTake up arms against the local lord and bring him to justice\n"
        "\t      before the king, knowing full well that the king would judge his\n"
        "\t      deed the act of a criminal.\n[0m\n"
        "\t[[0;31;1m4[0m] - [0;32mInform the local lord that you have uncovered the true nature of\n"
        "\t      the man's crimes and that you still intend to bring the man in but\n"
        "\t      require additional money lest you inadvertently mention this\n"
        "\t      episode to the king.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 4.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SixthQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("3");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYour travels have led you to a crypt. After vanquishing a wight, you\n"
        "find a vast, opulent treasure that will easily set you up for life. You take\n"
        "all you can and congratulate yourself for your good fortune. The next day while\n"
        "you are smugly sipping an ale in the local tavern, you hear that the local\n"
        "constable has arrested a man for ransacking the crypt. Do you[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mSilently offer a toast to yourself. It appears that the treasure\n"
        "\t      really is all yours!\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mTurn yourself in. If you tell the constable what happened and\n"
        "\t      return the treasure, it's no harm, no foul, right? They wouldn't\n"
        "\t      execute you for this, would they? Regardless, you can't let that\n"
        "\t      poor soul pay for your crime.\n[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mYou realize that life will be short for you if you're caught,\n"
        "\t      but you can't let that poor bastard take the fall for you so...\n"
        "\t      there's nothing for it but to plot a daring rescue. The jail\n"
        "\t      doesn't look all that sturdy.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SeventhQuestionIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("3");
    Selector->applySelection("1");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mPersonality Test[0m\n\n"
        "[0;36mYou are a lord and have a long-standing dispute with a fellow noble - \n"
        "Ser Osis of D'Liver. She has gone to the king complaining about how she has been\n"
        "inconvenienced and insulted by you because you did not have your servant\n"
        "whipped when they accidentally spilled her glass of wine on the table. She\n"
        "demands an apology. You respond[0m[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mSer Osis of D'Liver can kiss my arse. That wretched dung-beast\n"
        "\t      spilled her own wine!\n[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSer Osis of D'Liver is a drunkard and a buffoon. I will not punish\n"
        "\t      others for her inability to hold her liquor.\n[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mThe kind of woman who wants to enforce her ideas on others is\n"
        "\t      the kind of woman whose ideas are idiotic.\n[0m\n"
        "\t[[0;31;1m4[0m] - [0;32mSer Osis of D'Liver believes in the ideal that her birthright\n"
        "\t      allows her to step on others. An idealist is one who, on\n"
        "\t      noticing that a rose smells better than a cabbage, concludes\n"
        "\t      that it also makes a better soup.\n[0m\n"
        "[0;32;1mYou must select a number from 1 to 4.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectESTJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/estj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectESTP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/estp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectESFJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/esfj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectESFP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/esfp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectENTJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/eitj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectENTP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/eitp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectENFJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/eifj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectENFP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/eifp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectISTJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/istj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectISTP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("1");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/istp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectISFJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/isfj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectISFP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/isfp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectINTJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/iitj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectINTP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/iitp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectINFJ()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("1");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/iifj.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectINFP()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("2");
    Selector->applySelection("2");
    AnswerQuestionsTakeFirstChoice();

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/iifp.c"));
}

/////////////////////////////////////////////////////////////////////////////
void AllTraitsSetOnUserAndSelectorSetsTestTaken()
{
    Selector->initiateSelector(User);
    ExpectFalse(Selector->testTaken());
    AnswerQuestionsTakeFirstChoice();
    ExpectTrue(Selector->testTaken());

    ExpectTrue(User->isTraitOf("lib/modules/traits/archetypes/estj.c"));
    ExpectTrue(User->isTraitOf("lib/modules/traits/personality/loyal.c"));
    ExpectTrue(User->isTraitOf("lib/modules/traits/personality/dishonest.c"));
    ExpectTrue(User->isTraitOf("lib/modules/traits/personality/vulgar.c"));
}