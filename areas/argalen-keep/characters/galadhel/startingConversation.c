//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

private mapping maiwynPresent = ([
    "maiwyn":([
        "type":"presence",
        "value":({"maiwyn"})
    ])
]);

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Galadhel leans against the "
        "courtyard wall, watching the western road beyond the keep. "
        "When she sees you, her guarded expression gives way to a "
        "small, familiar smile. @S@'I hoped you would have a quiet "
        "morning before we found some trouble to walk into.'");
    addTopic("western road", "@D@Galadhel's gaze returns to the road. "
        "@S@'The farms have reported unfamiliar carts using the old "
        "track toward Tol-Dhurath. The reports do not agree on how "
        "many or what they carried. That is why I want to look, not "
        "why I think we should accuse anyone.'");
    addTopic("old friends", "@D@Galadhel studies you for a moment, "
        "then shrugs. @S@'We have been friends since before either "
        "of us knew what an Aegis oath meant. I am asking you because "
        "I trust you, not because your name or your father's gives "
        "me the right to command you.'");
    addRepeatableTopic("default", "@D@Galadhel gives you an "
        "inquiring look. @S@'What do you think? We can take the "
        "west track together, or stay here until you are ready.'");

    addResponse("first conversation", "What has happened on the west road?",
        "@D@You ask what brought her attention to the old track.");
    addResponseTopic("first conversation",
        "What has happened on the west road?", "western road");
    addResponse("first conversation", "Why ask me to come?",
        "@D@You ask whether this is an order or an invitation.");
    addResponseTopic("first conversation",
        "Why ask me to come?", "old friends");
    addResponse("first conversation", "Let's go to Tol-Dhurath together.",
        "@D@You agree to investigate with your friends.");
    addResponseEvent("first conversation",
        "Let's go to Tol-Dhurath together.", "startTolDhurath");

    addResponse("western road", "Let's go to Tol-Dhurath together.",
        "@D@You agree to investigate with your friends.");
    addResponseEvent("western road",
        "Let's go to Tol-Dhurath together.", "startTolDhurath");
    addResponse("western road", "Wait until we know more.",
        "@D@You tell Galadhel that you want more information first.");
    addResponseTopic("western road", "Wait until we know more.", "default");

    addResponse("old friends", "I will go with you.",
        "@D@You agree to travel with your friends.");
    addResponseEvent("old friends", "I will go with you.",
        "startTolDhurath");
    addResponse("old friends", "I need time to decide.",
        "@D@You tell Galadhel that you are not ready to leave yet.");
    addResponseTopic("old friends", "I need time to decide.", "default");

    addResponse("default", "Let's go to Tol-Dhurath together.",
        "@D@You agree to investigate with your friends.");
    addResponseEvent("default", "Let's go to Tol-Dhurath together.",
        "startTolDhurath");
    addResponse("default", "Tell me about our childhood.",
        "@D@You ask Galadhel for a story from before the Aegis.");
    addResponseTopic("default", "Tell me about our childhood.",
        "old friends");
    addResponse("default", "What have you noticed about the road?",
        "@D@You return to the reports from the farms.");
    addResponseTopic("default", "What have you noticed about the road?",
        "western road");

    addTopic("seilyndria", "@S@'Seilyndria? This cannot be - she was cast "
        "into the void a long time ago. What can this mean?' @D@says "
        "Galadhel, brow furrowed in thought, fear apparent on her face.");
    addTopic("seilyndria's return", "@D@Galadhel's expression tightens. "
        "@S@'I know what the old accounts say, but I have no proof "
        "that they explain what we saw. We must learn more before "
        "we decide what her return means.'");
    addTopic("speaking with maiwyn", "@S@'We owe Maiwyn patience. "
        "She has suffered more than we understand, and an awkward "
        "question does not give us the right to decide who she is.'");
    addTopic("maiwyn offended", "@D@Galadhel smirks and punches "
        "##InitiatorName## in the shoulder. She leans in and in an "
        "exaggerated faux whisper says, @S@'Classy move, dipshit!' "
        "@D@She turns to Maiwyn and gently says, @S@'Excuse my boorish "
        "friend, dear. @C@##ActorSubjective## is a bit of an "
        "acquired taste, but ##ActorSubjective## means well. "
        "@C@##ActorSubjective## meant simply to marvel that you "
        "were not dead, not to imply that you had joined this man who "
        "means our kingdom ill.");

    addTopicPrerequisite("seilyndria", maiwynPresent);
    addTopicPrerequisite("seilyndria's return", maiwynPresent);
    addTopicPrerequisite("speaking with maiwyn", maiwynPresent);
    addTopicPrerequisite("maiwyn offended", maiwynPresent);

    addResponse("seilyndria", "Could she truly have returned?",
        "@S@'I do not know. The old accounts said she was cast into "
        "the void, but we cannot treat an account as proof of what "
        "stands before us.'");
    addResponseTopic("seilyndria", "Could she truly have returned?",
        "seilyndria's return");
    addResponse("seilyndria", "What should we do?",
        "@S@'Keep our wits, learn what we can, and protect our "
        "companions. Fear is not a plan.'");
    addResponseTopic("seilyndria", "What should we do?",
        "seilyndria's return");
    addResponse("seilyndria's return", "Should we tell the others?",
        "@S@'Tell them what we saw, not what we fear it means. "
        "They deserve facts before rumors.'");
    addResponseTopic("seilyndria's return",
        "Should we tell the others?", "speaking with maiwyn");
    addResponse("maiwyn offended", "I should have chosen my words better.",
        "@S@'Aye. But you can still listen to her answer instead "
        "of deciding what she meant.'");
    addResponseTopic("maiwyn offended",
        "I should have chosen my words better.", "speaking with maiwyn");
    addResponse("maiwyn offended", "Why are you defending me?",
        "@S@'I am defending her right to be treated fairly, and "
        "your chance to do better.'");
    addResponse("speaking with maiwyn", "How do I begin?",
        "@S@'Ask what she needs, then let her answer. Do not make "
        "her carry the burden of easing your uncertainty.'");
}
