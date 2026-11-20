//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'If you are hurt, tell me where "
        "and how. I will not sell you a bottle without knowing what "
        "you mean to treat.'");
    addTopic("common remedies", "@S@'For a scrape, clean water and a "
        "bandage. For a fever, rest and a measured draught. The harder "
        "cases belong with a trained healer.'");
    addTopic("safe treatment", "@D@Halan sets the jar down and "
        "speaks carefully. @S@'Tell me what was taken and how much. "
        "Do not mix remedies because someone said it worked for "
        "them. If the person is in danger, fetch a healer at once.'");
    addTopic("herbs and remedies", "@S@'A plant is not safe just "
        "because it is natural. I label every jar and keep the "
        "measured remedies apart from the raw herbs.'");
    addTopic("when to seek a healer", "@S@'If a wound is deep, a "
        "fever is worsening, or someone cannot keep a remedy down, "
        "bring in a trained healer. Do not wait for a shopkeeper to "
        "guess at a serious illness.'");
    addTopic("gathering safely", "@S@'Learn from someone who can "
        "identify plants in the field. Begin with common species "
        "and never gather anything you cannot name with confidence.'");
    addTopic("remedy labels", "@D@Halan turns a jar so its label "
        "faces you. @S@'The name, measure, and instructions belong "
        "together. If any of those are missing, do not take it.'");

    addResponse("first conversation", "Do you have something for a cut?",
        "@S@'I have clean dressings and a mild wash. Sit down and let "
        "me see it first.'");
    addResponseTopic("first conversation", "Do you have something for a cut?",
        "common remedies");
    addResponse("first conversation", "Can I buy something for a fever?",
        "@S@'I can ask about the symptoms and suggest a mild remedy. "
        "A serious or lasting fever needs a trained healer.'");
    addResponseTopic("first conversation",
        "Can I buy something for a fever?", "safe treatment");
    addResponse("first conversation", "Where do you get your herbs?",
        "@S@'From reliable gatherers who know what they are picking. "
        "I would rather sell less than put a dangerous plant in the "
        "wrong hands.'");
    addResponseTopic("first conversation",
        "Where do you get your herbs?", "herbs and remedies");
    addResponse("common remedies", "Can I use a stronger draught?",
        "@S@'Not without knowing what is wrong. More of a remedy "
        "does not mean more help.'");
    addResponseTopic("common remedies", "Can I use a stronger draught?",
        "safe treatment");
    addResponse("herbs and remedies", "Can you teach me to gather?",
        "@S@'Learn from an experienced herbalist in the field. "
        "Here, I can show you how I label and store what comes in.'");
    addResponseTopic("herbs and remedies",
        "Can you teach me to gather?", "gathering safely");
    addResponse("gathering safely", "How do I know a plant is safe?",
        "@S@'Do not rely on appearance alone. Learn its season, "
        "where it grows, and how to tell it from similar plants.'");
    addResponseTopic("gathering safely",
        "How do I know a plant is safe?", "herbs and remedies");
    addResponse("safe treatment", "When is a healer necessary?",
        "@S@'When the symptoms are severe, worsening, or unclear. "
        "I can offer common supplies, but I will not pretend to "
        "replace a healer.'");
    addResponseTopic("safe treatment", "When is a healer necessary?",
        "when to seek a healer");
    addResponse("remedy labels", "What if I cannot read the label?",
        "@S@'Ask me before you use it. If I am not here, leave the "
        "jar alone until someone can identify it.'");
    addResponseTopic("remedy labels", "What if I cannot read the label?",
        "safe treatment");
    addResponse("when to seek a healer", "Can I bring someone here?",
        "@S@'Yes, if they can travel safely. If they cannot, send "
        "someone for a healer and tell them exactly what happened.'");
    addResponseTopic("when to seek a healer",
        "Can I bring someone here?", "common remedies");
}
