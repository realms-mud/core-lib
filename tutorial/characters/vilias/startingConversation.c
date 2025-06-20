//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
// Vilias appears and introduces herself
private void ViliasAppearsTopic()
{
    addTopic("vilias-appears",
        "@D@A misty figure coalesces out of thin air. She speaks, her voice "
        "both sweet and chilling:@S@\"Nay, I am no foe. In fact, you should "
        "thank me. For you were about to get yourselves killed.\"");

    addTopicInterjection("vilias-appears",
        "/tutorial/characters/galadhel/galadhel.c", "vilias-appears");
    addTopicInterjection("vilias-appears",
        "/tutorial/characters/alberich/alberich.c", "vilias-appears");
    addTopicInterjection("vilias-appears",
        "/tutorial/characters/halgaladh/halgaladh.c", "vilias-appears");

    addResponse("vilias-appears",
        "If you are, in fact, a benefactor, explain your purpose.",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"If you are, in fact, a benefactor, explain your purpose.\"");
    addResponseTopic("vilias-appears",
        "If you are, in fact, a benefactor, explain your purpose.",
        "vilias-purpose-1");

    addResponse("vilias-appears", "Who are you?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Who are you?\"");
    addResponseTopic("vilias-appears", "Who are you?", "vilias-identity");

    addResponse("vilias-appears", "What are you?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What are you?\"");
    addResponseTopic("vilias-appears", "What are you?", "vilias-nature");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "Who are you?"
private void ViliasIdentityTopic()
{
    addTopic("vilias-identity",
        "@S@\"Who I am is not important. What matters is what you do next.\"");

    addResponse("vilias-identity", "Then explain your purpose.",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Then explain your purpose.\"");
    addResponseTopic("vilias-identity", "Then explain your purpose.", "vilias-purpose-1");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "What are you?"
private void ViliasNatureTopic()
{
    addTopic("vilias-nature",
        "@S@\"A messenger. A watcher. A hand that cannot touch.\"");

    addResponse("vilias-nature", "Then explain your purpose.",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Then explain your purpose.\"");
    addResponseTopic("vilias-nature", "Then explain your purpose.", "vilias-purpose-1");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias explains her purpose
private void ViliasPurposeOneTopic()
{
    addTopic("vilias-purpose-1",
        "@S@\"Make no mistake, fair sir. Were I an enemy, you would be lying "
        "slain before my feet. Nay, that is not bluster, but simple truth.\"");

    addResponse("vilias-purpose-1", "Go on.",
        "@C@##InitiatorName## ##ResponseInfinitive::prompt##, @S@\"Go on.\"");
    addResponseTopic("vilias-purpose-1", "Go on.", "vilias-purpose-2");

    addResponse("vilias-purpose-1", "Why warn us at all?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why warn us at all?\"");
    addResponseTopic("vilias-purpose-1", "Why warn us at all?", "vilias-why-warn");

    addResponse("vilias-purpose-1", "If you could kill us, why not do so?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"If you could kill us, why not do so?\"");
    addResponseTopic("vilias-purpose-1", "If you could kill us, why not do so?", "vilias-why-not-kill");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "Why warn us at all?"
private void ViliasWhyWarnTopic()
{
    addTopic("vilias-why-warn",
        "@S@\"Because your deaths would serve no purpose, and I have no wish to "
        "see hope extinguished.\"");

    addResponse("vilias-why-warn", "Go on.",
        "@C@##InitiatorName## ##ResponseInfinitive::prompt##, @S@\"Go on.\"");
    addResponseTopic("vilias-why-warn", "Go on.", "vilias-purpose-2");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "If you could kill us, why not do so?"
private void ViliasWhyNotKillTopic()
{
    addTopic("vilias-why-not-kill",
        "@S@\"Because I am not your enemy. I am here to offer a choice.\"");

    addResponse("vilias-why-not-kill", "Go on.",
        "@C@##InitiatorName## ##ResponseInfinitive::prompt##, @S@\"Go on.\"");
    addResponseTopic("vilias-why-not-kill", "Go on.", "vilias-purpose-2");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias describes the threat
private void ViliasPurposeTwoTopic()
{
    addTopic("vilias-purpose-2",
        "@S@\"Beyond this door, your enemies are creating that which robs one "
        "of death - that is to say death as it should be. Everyone serves a "
        "purpose in life and that purpose continues once their corporeal body "
        "ceases to function. What your enemies are doing completely destroys "
        "that, for the soul of those they take is corrupted and that beautiful "
        "thing that they were to become is no more.\"");

    addResponse("vilias-purpose-2", "What do you mean?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What do you mean?\"");
    addResponseTopic("vilias-purpose-2", "What do you mean?", "vilias-purpose-3");

    addResponse("vilias-purpose-2", "Why does that matter to you?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why does that matter to you?\"");
    addResponseTopic("vilias-purpose-2", "Why does that matter to you?", "vilias-matter");

    addResponse("vilias-purpose-2", "What are they creating?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What are they creating?\"");
    addResponseTopic("vilias-purpose-2", "What are they creating?", "vilias-creating");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "Why does that matter to you?"
private void ViliasMatterTopic()
{
    addTopic("vilias-matter",
        "@S@\"Because the balance is threatened. The dead deserve their rest, "
        "and the living their hope.\"");

    addResponse("vilias-matter", "Go on.",
        "@C@##InitiatorName## ##ResponseInfinitive::prompt##, @S@\"Go on.\"");
    addResponseTopic("vilias-matter", "Go on.", "vilias-purpose-3");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers "What are they creating?"
private void ViliasCreatingTopic()
{
    addTopic("vilias-creating",
        "@S@\"Abominations. Corpses bound to will, souls twisted to serve.\"");

    addResponse("vilias-creating", "Go on.",
        "@C@##InitiatorName## ##ResponseInfinitive::prompt##, @S@\"Go on.\"");
    addResponseTopic("vilias-creating", "Go on.", "vilias-purpose-3");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias explains her role and the danger
private void ViliasPurposeThreeTopic()
{
    addTopic("vilias-purpose-3",
        "@S@\"You ask my purpose? I am an emissary of the dead, here to reclaim "
        "what is rightfully theirs. And there are a lot of them behind that "
        "door. They are aware of you and they are waiting. If you open that "
        "door, you will fall and, in falling, you will join the ranks of the "
        "accursed.\"");

    addResponse("vilias-purpose-3", "Is there another way?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Is there another way?\"");
    addResponseTopic("vilias-purpose-3", "Is there another way?", "vilias-purpose-4");

    addResponse("vilias-purpose-3", "What do you want from us?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What do you want from us?\"");
    addResponseTopic("vilias-purpose-3", "What do you want from us?", "vilias-purpose-4");

    addResponse("vilias-purpose-3", "Why warn us if we are doomed?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why warn us if we are doomed?\"");
    addResponseTopic("vilias-purpose-3", "Why warn us if we are doomed?", "vilias-purpose-4");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias offers a choice and a path
private void ViliasPurposeFourTopic()
{
    addTopic("vilias-purpose-4",
        "@S@\"But as with all things, there are many paths that may be taken "
        "to reach an end. You want to defeat your foes and I (laughing) wish "
        "to see you succeed. I offer you a different path. Take the stairs "
        "down. Continue the path and you will come across two doors. Take the "
        "one to the north and follow it to its end. There, you will find those "
        "who will aid you. Tarry not and take not any side paths, for you are "
        "surrounded by great danger. Spurn this advice and I fear that your "
        "quest will fail... you will also condemn something wonderful to "
        "unlife.\"");

    addTopicInterjection("vilias-purpose-4",
        "/tutorial/characters/thomas/thomas.c", "vilias-purpose-4");

    addResponse("vilias-purpose-4",
        "Why should we believe you? This could very well be a trap.",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why should we believe you? This could very well be a trap.\"");
    addResponseTopic("vilias-purpose-4",
        "Why should we believe you? This could very well be a trap.",
        "vilias-trap");

    addResponse("vilias-purpose-4", "What if we ignore your advice?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What if we ignore your advice?\"");
    addResponseTopic("vilias-purpose-4", "What if we ignore your advice?", "vilias-trap");

    addResponse("vilias-purpose-4", "Who are these allies you mention?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Who are these allies you mention?\"");
    addResponseTopic("vilias-purpose-4", "Who are these allies you mention?", "vilias-trap");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers suspicion and offers to answer questions
private void ViliasTrapTopic()
{
    addTopic("vilias-trap",
        "@S@\"Oh, it is such a distrustful world we live in. (laughs) You "
        "speak wisely. It could, indeed, be a trap. I fear that there is "
        "little I could say now that would allay your suspicions. I could "
        "tell you that there are 138 black-robed menaces within this place, "
        "but that really says nothing of the threat. I could tell you that "
        "the one you might wish to rescue is the greatest, most powerful "
        "enemy of your enemies. Perhaps you wish me to reveal his identity? "
        "Alas, it is not my place to do so.\"");

    addTopicInterjection("vilias-trap",
        "/tutorial/characters/halgaladh/halgaladh.c", "vilias-trap");

    addResponse("vilias-trap",
        "Will you suffer some questions - to show your goodwill?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Will you suffer some questions - to show your goodwill?\"");
    addResponseTopic("vilias-trap",
        "Will you suffer some questions - to show your goodwill?",
        "vilias-questions");

    addResponse("vilias-trap", "Tell us something only a true ally would know.",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Tell us something only a true ally would know.\"");
    addResponseTopic("vilias-trap", "Tell us something only a true ally would know.", "vilias-questions");

    addResponse("vilias-trap", "What is your stake in this?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What is your stake in this?\"");
    addResponseTopic("vilias-trap", "What is your stake in this?", "vilias-questions");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers questions about the enemy and the place
private void ViliasQuestionsTopic()
{
    addTopic("vilias-questions",
        "@S@\"(sultry laugh) As you wish. Ask, and I will answer as I am able.\"");

    addResponse("vilias-questions",
        "The leader of these... creatures is said to be within. What do you "
        "know of him?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"The leader of these... creatures is said to be within. What do you "
        "know of him?\"");
    addResponseTopic("vilias-questions",
        "The leader of these... creatures is said to be within. What do you "
        "know of him?", "vilias-leader");

    addResponse("vilias-questions", "What is this place?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What is this place?\"");
    addResponseTopic("vilias-questions", "What is this place?", "vilias-leader");

    addResponse("vilias-questions", "What are the black-robed ones?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What are the black-robed ones?\"");
    addResponseTopic("vilias-questions", "What are the black-robed ones?", "vilias-leader");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers about the leader and the orb
private void ViliasLeaderTopic()
{
    addTopic("vilias-leader",
        "@S@\"(shrugs) He is of little consequence. He meddles in that which "
        "is unwise and his time on this world is not long. He will find the "
        "deep embrace of death if not today, perhaps tomorrow.\"");

    addResponse("vilias-leader",
        "There is supposed to be a device of great power within here. What do "
        "you know of it?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"There is supposed to be a device of great power within here. "
        "What do you know of it?\"");
    addResponseTopic("vilias-leader",
        "There is supposed to be a device of great power within here. What do "
        "you know of it?", "vilias-orb");

    addResponse("vilias-leader", "Who is his master?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Who is his master?\"");
    addResponseTopic("vilias-leader", "Who is his master?", "vilias-orb");

    addResponse("vilias-leader", "Why is he here?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why is he here?\"");
    addResponseTopic("vilias-leader", "Why is he here?", "vilias-orb");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias explains the orb and non-intervention
private void ViliasOrbTopic()
{
    addTopic("vilias-orb",
        "@S@\"It must be destroyed, though it will be up to you to find a way. "
        "I can tell you somewhat of it, though my knowledge is limited. This "
        "Orb of Obedience... it creates devices that are used to control the "
        "corporeal remains of its victims. In use, it binds the soul to the "
        "dead form and corrupts the soul toward evil. To use it, the "
        "Nightmaster grasps it and forces his will upon the thing... More I do "
        "not know. Today, that is not your purpose. You have not the strength "
        "to wrest it from your enemies.\"");

    addTopicInterjection("vilias-orb",
        "/tutorial/characters/thomas/thomas.c", "vilias-orb");

    addResponse("vilias-orb",
        "If you are as powerful as you say and can lay this unit to waste, "
        "why do you not enter now and crush this evil before it gains more "
        "strength?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"If you are as powerful as you say and can lay this unit to waste, "
        "why do you not enter now and crush this evil before it gains more "
        "strength?\"");
    addResponseTopic("vilias-orb",
        "If you are as powerful as you say and can lay this unit to waste, "
        "why do you not enter now and crush this evil before it gains more "
        "strength?", "vilias-nonintervention");

    addResponse("vilias-orb", "How can we destroy it?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"How can we destroy it?\"");
    addResponseTopic("vilias-orb", "How can we destroy it?", "vilias-nonintervention");

    addResponse("vilias-orb", "What happens if it is used?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What happens if it is used?\"");
    addResponseTopic("vilias-orb", "What happens if it is used?", "vilias-nonintervention");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias explains her non-intervention
private void ViliasNoninterventionTopic()
{
    addTopic("vilias-nonintervention",
        "@S@\"That is the easiest question to answer, though it may well be "
        "the answer you like the least. I am not permitted to intervene. "
        "Indeed, by doing what I am right now, I am flirting with... a grey "
        "area and have, perhaps, taken one or two too many liberties "
        "interpreting my orders.\"");

    addTopicInterjection("vilias-nonintervention",
        "/tutorial/characters/donald/donald.c", "vilias-nonintervention");

    addResponse("vilias-nonintervention", "What do you say to that?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What do you say to that?\"");
    addResponseTopic("vilias-nonintervention", "What do you say to that?", "vilias-truss");

    addResponse("vilias-nonintervention", "Who forbids you?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Who forbids you?\"");
    addResponseTopic("vilias-nonintervention", "Who forbids you?", "vilias-truss");

    addResponse("vilias-nonintervention", "Why risk yourself to warn us?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why risk yourself to warn us?\"");
    addResponseTopic("vilias-nonintervention", "Why risk yourself to warn us?", "vilias-truss");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias answers about trust and her name
private void ViliasTrussTopic()
{
    addTopic("vilias-truss",
        "@S@\"(laughing) You might find me a trifle difficult to 'truss up' in "
        "my current form, dear fellow. 'Tis a good thing that you amuse me, "
        "for otherwise I might take offense. (laughter replaced by downright "
        "evil hiss as she faces Donald) You have uncovered my ruse. Prepare to "
        "die! (after a pause, she laughs) Nay, I do not mean to mock you, and "
        "I respect your distrust. In your place, I would likely behave the "
        "same way. I ask you to trust me but do little enough to earn that "
        "trust. Alas, I must ask you to take my advice on faith. Already, I do "
        "more than I am allowed.\"");

    addTopicInterjection("vilias-truss",
        "/tutorial/characters/halgaladh/halgaladh.c", "vilias-truss");

    addResponse("vilias-truss",
        "What can you tell us of the Nightmaster? And your name?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What can you tell us of the Nightmaster? And your name?\"");
    addResponseTopic("vilias-truss",
        "What can you tell us of the Nightmaster? And your name?", "vilias-name");

    addResponse("vilias-truss", "You seem to enjoy this.",
        "@C@##InitiatorName## ##ResponseInfinitive::say##, "
        "@S@\"You seem to enjoy this.\"");
    addResponseTopic("vilias-truss", "You seem to enjoy this.", "vilias-name");

    addResponse("vilias-truss", "If you are not our enemy, what are you?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"If you are not our enemy, what are you?\"");
    addResponseTopic("vilias-truss", "If you are not our enemy, what are you?", "vilias-name");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias gives her name and offers a final warning
private void ViliasNameTopic()
{
    addTopic("vilias-name",
        "@S@\"As I said, he is of little consequence. His master, on the other "
        "hand, is another matter entirely. Of him, I cannot speak of right "
        "now, for your danger increases the longer you tarry. Fear not though, "
        "that shall become known to you soon enough. (pause as if considering) "
        "As for me, you may call me Hope.\"");

    addTopicInterjection("vilias-name",
        "/tutorial/characters/halgaladh/halgaladh.c", "vilias-name");
    addTopicInterjection("vilias-name",
        "/tutorial/characters/donald/donald.c", "vilias-name");

    addResponse("vilias-name",
        "Why do you trust this wraith? What has it done to earn even the "
        "slightest trust?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why do you trust this wraith? What has it done to earn even the "
        "slightest trust?\"");
    addResponseTopic("vilias-name",
        "Why do you trust this wraith? What has it done to earn even the "
        "slightest trust?", "vilias-harlot");

    addResponse("vilias-name", "Why 'Hope'?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why 'Hope'?\"");
    addResponseTopic("vilias-name", "Why 'Hope'?", "vilias-harlot");

    addResponse("vilias-name", "What are you really?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"What are you really?\"");
    addResponseTopic("vilias-name", "What are you really?", "vilias-harlot");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias gives a final warning and allows the player to end the conversation
private void ViliasHarlotTopic()
{
    addTopic("vilias-harlot",
        "@S@\"(laughing) Harlot? Witch? Wraith? Thou must have been wounded "
        "deeply by a woman once to have reserved such hateful terms for me. "
        "Yes, Eledhel is in danger and yes, you must warn the king's son. "
        "That danger will be amplified if you do not act decisively now. If I "
        "can give any words of comfort, I can say only this: not from this "
        "quarter does the doom of Eledhel lie.\"");

    addResponse("vilias-harlot",
        "Thank you, m'lady, for the information. We shall take your advice.",
        "@C@##InitiatorName## ##ResponseInfinitive::say##, "
        "@S@\"Thank you, m'lady, for the information. We shall take your advice.\"");
    addResponseTopic("vilias-harlot",
        "Thank you, m'lady, for the information. We shall take your advice.",
        "vilias-exit");

    addResponse("vilias-harlot", "Is there anything else you can tell us?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Is there anything else you can tell us?\"");
    addResponseTopic("vilias-harlot", "Is there anything else you can tell us?", "vilias-exit");

    addResponse("vilias-harlot", "Why warn us about Eledhel?",
        "@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@\"Why warn us about Eledhel?\"");
    addResponseTopic("vilias-harlot", "Why warn us about Eledhel?", "vilias-exit");
}

/////////////////////////////////////////////////////////////////////////////
// Vilias exits
private void ViliasExitTopic()
{
    addTopic("vilias-exit",
        "@S@Vilias fades away, leaving only a lingering sense of unease and "
        "hope.");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ViliasAppearsTopic();
    ViliasIdentityTopic();
    ViliasNatureTopic();
    ViliasPurposeOneTopic();
    ViliasWhyWarnTopic();
    ViliasWhyNotKillTopic();
    ViliasPurposeTwoTopic();
    ViliasMatterTopic();
    ViliasCreatingTopic();
    ViliasPurposeThreeTopic();
    ViliasPurposeFourTopic();
    ViliasTrapTopic();
    ViliasQuestionsTopic();
    ViliasLeaderTopic();
    ViliasOrbTopic();
    ViliasNoninterventionTopic();
    ViliasTrussTopic();
    ViliasNameTopic();
    ViliasHarlotTopic();
    ViliasExitTopic();
}
