//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Liora folds a leather cuff "
        "over her palm and gestures toward the fitting space.");
    addTopic("travel armor", "@S@'For a long ride, comfort matters as "
        "much as protection. If you cannot lift your arm or turn your "
        "shoulder, the armor is wrong.'");
    addTopic("leather care", "@S@'Brush off grit and let wet leather "
        "dry slowly. Heat will make it stiff, and a stiff seam can "
        "break when you need it most.'");
    addTopic("fitting", "@D@Liora gestures toward the fitting space. "
        "@S@'I need to see how you stand and move. Armor fitted to "
        "someone else may pinch you in all the wrong places.'");
    addTopic("riding gear", "@S@'Riding gear must stay secure when "
        "you mount and dismount. A loose buckle can catch at the "
        "worst moment, so test every strap from the saddle.'");
    addTopic("leather repairs", "@D@Liora runs a finger along a "
        "stitched seam. @S@'A small tear can be reinforced. If the "
        "leather has gone brittle, stitching will only hide the "
        "weakness for a little while.'");

    addResponse("first conversation", "What would you recommend for travel?",
        "@S@'Show me what you already wear and where you are going. "
        "Then we can talk about weight.'");
    addResponseTopic("first conversation",
        "What would you recommend for travel?", "travel armor");
    addResponse("first conversation", "Can you adjust a leather harness?",
        "@S@'Yes. Bring it here and I will check the fit before "
        "changing anything.'");
    addResponseTopic("first conversation",
        "Can you adjust a leather harness?", "fitting");
    addResponse("first conversation", "How should I care for leather?",
        "@S@'Keep it clean, let it dry away from a fire, and use "
        "a little oil when it begins to stiffen.'");
    addResponseTopic("first conversation",
        "How should I care for leather?", "leather care");
    addResponse("travel armor", "Should I wear heavier armor on the road?",
        "@S@'Not if it keeps you from moving or wears you out. "
        "Choose what you can use well for the whole journey.'");
    addResponseTopic("travel armor",
        "Should I wear heavier armor on the road?", "fitting");
    addResponse("fitting", "What should I bring to a fitting?",
        "@S@'Wear the clothes you expect to wear beneath the armor. "
        "That gives me a proper measure.'");
    addResponse("first conversation", "Can you fit gear for a horse?",
        "@S@'I can adjust straps and leather fittings. Tell me what "
        "the gear carries and how it is fastened.'");
    addResponseTopic("first conversation",
        "Can you fit gear for a horse?", "riding gear");
    addResponse("riding gear", "How do I check it before riding?",
        "@S@'Fasten it as you normally would, then test each strap "
        "with the horse standing still. Have someone check what "
        "you cannot see.'");
    addResponseTopic("riding gear",
        "How do I check it before riding?", "leather repairs");
    addResponse("leather repairs", "Can a brittle strap be saved?",
        "@S@'Sometimes it can be replaced; sometimes the whole "
        "piece has weakened. Bring it in and I will inspect it.'");
    addResponseTopic("leather repairs",
        "Can a brittle strap be saved?", "fitting");
}
