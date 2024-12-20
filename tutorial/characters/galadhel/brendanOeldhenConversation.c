//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void FindingHaldor()
{
    addTopic("haldor is dead", "@D@Galadhel crouches down beside the corpse. @S@`"
        "Haldor has fallen.' @D@She intently examines an arrow that is "
        "protruding from Haldor's temple.");
    addTopicInterjection("haldor is dead",
        "/tutorial/characters/halgaladh/halgaladh.c",
        "aye but how", 1);

    addTopic("I do not know", "@D@Galadhel grimaces, @S@`Good question. Given "
        "the signs here, that arrow was fired from the west.'");
    addTopicInterjection("I do not know",
        "/tutorial/characters/donald/donald.c",
        "Does it matter", 1);

    addTopic("look over there", "@D@Galadhel points to the west and hisses, "
        "@S@`Look! Over there.'");
    addTopicEvent("look over there", "moveCharactersToOnTheTrailPartOne");

    addTopic("What are we missing", "@D@Galadhel frowns as she looks at the "
        "corpse, @S@`What are we missing?'");
    addTopicEvent("What are we missing", "moveCharactersToOnTheTrailPartFour");

    addTopic("the corpse is human", "@D@Galadhel goes over to the fallen robed "
        "figure and investigates. She looks at Donald and says, @S@`Sir, the "
        "corpse is human. Male. Seems to have a taste for sinister-looking "
        "accessories.'");
    addTopicInterjection("the corpse is human",
        "/tutorial/characters/donald/donald.c",
        "let's get these bastards", 1);

    addTopic("whisper about dead to Donald", "@D@Galadhel crouches beside "
        "Donald and whispers, @S@`Do we still want any alive? Certainly "
        "the dead are worthless. There are the robed ones, however.'");
    addTopicInterjection("whisper about dead to Donald",
        "/tutorial/characters/donald/donald.c",
        "take him out", 1);

    addTopic("I guess I'll just kill this guy", "@D@Galadhel sighs in "
        "frustration, clearly annoyed that Donald chose to give their position "
        "away. She knocks an arrow and looses it, embedding it into the "
        "throat of one of the black-robed figures. As it falls to its death, "
        "one of the walking corpses falls to the ground as though it were "
        "a marionette whose strings had been cut.");
    addTopicInterjection("I guess I'll just kill this guy",
        "/tutorial/characters/alberich/alberich.c",
        "daft bastard", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void YouKnowMe()
{
    addTopic("you know me?", "@D@Galadhel tilts her head, curious now and "
        "uses the tip of the arrow in her hand to ease aside the fabric "
        "of the hood of his robe. Her features register recognition after "
        "a moment and she says softly, @S@`You know me? Who are you?'");

    addTopicInterjection("you know me?",
        "/tutorial/characters/brendan/brendan.c",
        "yes, I know you", 1);

    addTopic("Interruptions aren't your only concern", 
        "@D@Galadhel offers a small smile to "
        "the robed figure now, eerily sincere. Her voice, however, lowers "
        "to a whisper as she stretches back her bow string, arrow at the "
        "ready and aimed right between the legs of her prey. @S@`Speak now.'");

    addTopicInterjection("Interruptions aren't your only concern", 
        "/tutorial/characters/halgaladh/halgaladh.c",
        "no more mushroom farmers", 1);

    addTopicInterjection("Interruptions aren't your only concern",
        "/tutorial/characters/brendan/brendan.c",
        "I was Phaedra", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void DidItMeanAnythingToMe()
{
    addTopic("did it mean anything to me?", "@D@Galadhel looks something "
        "between shocked and murderous at this point. When Donald asks his "
        "questions, she is prodded out of her moment of evil contemplation. "
        "She hisses softly in return, @S@`Did it mean anything to me?' @D@ "
        "She blinks. Once. Her voice raises as she steps toward Donald. @S@ "
        "`Did it mean anything to me?' @D@Without hesitation, she takes "
        "advantage of Donald's recent injuries and casual conversational "
        "attitude to quickly and precisely offer a left hook to his temple. "
        "After he falls, she says politely to his unconscious form, @S@"
        "`As a matter of fact it was very meaningful. He knew my brother. "
        "That means this man was Phaedra. It means he had access to some of "
        "our country's best intelligence. It also means that this group of "
        "black-robed, bad-tasted hoodlums may have some connection to our own "
        "government.'");
    addResponse("did it mean anything to me?", "@I@Continue@E@", "");

    addTopic("did it mean anything to me part 2", "@D@Galadhel leans closer, "
        "looking as though she is listening to something Donald is obviously "
        "in no position to utter. @S@`Oh yes! I'm so glad you asked, esteemed "
        "commander. I am still searching for my brother. This man not only "
        "could have shed some light on that, but more about what we're up "
        "against here and why his group wantonly slayed so many of our "
        "cherished friends. It's not every day close to fifteen percent of "
        "the Aegis is murdered.' @D@She lets her words trail off, a litany "
        "of colorful anecdotes that no noble lady of the realm ought to "
        "have heard in her day, nevermind uttered. As she disappears into the "
        "woods, she can be heard to say, @S@`I'll give you meaning, you "
        "stupid son of a ...'");
    addResponseTopic("did it mean anything to me?", "@I@Continue@E@", 
        "did it mean anything to me part 2");
    addTopicEvent("did it mean anything to me part 2", 
        "halgaladhAwakensDonald");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("brendan - need a decorator", "@D@Galadhel chuckles, @S@`Home? You are "
        "in serious need of a decorator, my friend. Even so, I shall not hold "
        "your bad taste against you. Yet. We have followed our prey here, ones "
        "who killed our comrades in our encampment then set their corpses in "
        "motion to try and add us to whatever fell plan is in motion. So, rather "
        "than labelling one another and whining self-defense, how about we have "
        "a conversation.'");

    addTopic("threaten brendan", "@D@Galadhel nocks an arrow and draws back her "
        "bow as she interjects, @S@`Given your handiness with corpses, you also "
        "seem to share the same talent as the one who attacked our camp.'");
    addTopicInterjection("threaten brendan",
        "/tutorial/characters/brendan/brendan.c",
        "slow down, Sparky", 1);

    FindingHaldor();
    YouKnowMe();
    DidItMeanAnythingToMe();
}
