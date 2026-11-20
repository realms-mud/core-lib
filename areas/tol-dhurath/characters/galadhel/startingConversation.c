//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
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
