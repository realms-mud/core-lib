//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Seli places a narrow blade on "
        "the bench, edge turned safely away from you.");
    addTopic("small blades", "@S@'A short blade is not an excuse for "
        "poor balance. The hand should know where the point is without "
        "needing to look.'");
    addTopic("edge care", "@D@Seli tests the edge with a whetstone "
        "and a practiced touch. @S@'Use a stone meant for the blade. "
        "A careless sharpening can ruin a good edge.'");
    addTopic("choosing a blade", "@S@'The shape should suit the hand "
        "and the task. Do not buy a blade because someone told you "
        "it makes you look dangerous.'");
    addTopic("carrying a blade", "@S@'A blade belongs in a sound "
        "sheath, secured where it will not fall or catch. Keep it "
        "sheathed in town unless you have a clear reason to draw it.'");
    addTopic("safe handling", "@S@'Pass a blade hilt first and keep "
        "its edge turned away from everyone. If you are unsure how "
        "to handle it, ask before you lift it.'");

    addResponse("first conversation", "Can you sharpen this?",
        "@S@'I can. Leave it here and I will have it ready before dusk.'");
    addResponseTopic("first conversation", "Can you sharpen this?",
        "small blades");
    addResponse("first conversation", "How do I choose a dagger?",
        "@S@'Tell me how you plan to use it. A tool for a belt is "
        "not necessarily right for a fight.'");
    addResponseTopic("first conversation", "How do I choose a dagger?",
        "choosing a blade");
    addResponse("first conversation", "Can you repair a broken hilt?",
        "@S@'Bring the blade in. The hilt can be replaced if the "
        "tang is sound.'");
    addResponseTopic("first conversation",
        "Can you repair a broken hilt?", "small blades");
    addResponse("small blades", "How often should I sharpen it?",
        "@S@'When the edge needs it, not every time you use it. "
        "Clean it after work and store it dry.'");
    addResponseTopic("small blades", "How often should I sharpen it?",
        "edge care");
    addResponse("choosing a blade", "What makes a dagger safe to carry?",
        "@S@'A sound sheath, a secure hilt, and the judgment not "
        "to draw it carelessly.'");
    addResponseTopic("choosing a blade",
        "What makes a dagger safe to carry?", "carrying a blade");
    addResponse("first conversation", "How should I handle a dagger?",
        "@S@'Keep the edge clear of yourself and anyone nearby. "
        "If you are new to blades, learn with a blunted one first.'");
    addResponseTopic("first conversation",
        "How should I handle a dagger?", "safe handling");
    addResponse("carrying a blade", "What if the sheath is loose?",
        "@S@'Do not carry it that way. I can check the fit and "
        "repair the sheath before you take it out.'");
    addResponseTopic("carrying a blade",
        "What if the sheath is loose?", "small blades");
    addResponse("safe handling", "Can I practice here?",
        "@S@'Not with a live blade in a crowded shop. Find a "
        "qualified instructor and a proper practice space.'");
    addResponseTopic("safe handling", "Can I practice here?",
        "choosing a blade");
}
