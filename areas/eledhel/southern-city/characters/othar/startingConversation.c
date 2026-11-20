//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Othar tests the curve of a bow "
        "and nods to you.");
    addTopic("bow care", "@S@'Keep the string dry, unstring the bow "
        "when you store it, and never leave it beside a fire. Wood "
        "forgets its shape if you are careless.'");
    addTopic("choosing a bow", "@D@Othar measures the marked draw "
        "line with a glance. @S@'The bow must suit your reach and "
        "strength. A bow that is too heavy will slow every shot.'");
    addTopic("arrows", "@S@'A straight shaft and sound fletching "
        "matter as much as the head. I check each arrow before it "
        "leaves the shop.'");
    addTopic("bow practice", "@S@'A steady shot begins with a "
        "comfortable stance and a controlled draw. Practice at a "
        "safe target, and never loose an arrow without knowing "
        "what lies beyond it.'");
    addTopic("field repairs", "@S@'A damaged bowstring should be "
        "replaced before the next shot. I can check the limbs and "
        "string here, but do not test a questionable bow at full draw.'");

    addResponse("first conversation", "Can you fit a bow to me?",
        "@S@'I can. Tell me how you draw and what you mean to hunt.'");
    addResponseTopic("first conversation", "Can you fit a bow to me?",
        "bow care");
    addResponse("first conversation", "What should I look for in a bow?",
        "@S@'One you can draw smoothly and hold steady. Let me "
        "measure your reach before you choose.'");
    addResponseTopic("first conversation",
        "What should I look for in a bow?", "choosing a bow");
    addResponse("first conversation", "Do you make arrows as well?",
        "@S@'I keep arrows in stock and make them to order. The "
        "right shaft depends on the bow and the work you expect it to do.'");
    addResponseTopic("first conversation",
        "Do you make arrows as well?", "arrows");
    addResponse("bow care", "How should I store a bow?",
        "@S@'Dry it, unstring it, and keep it away from heat. "
        "Check the limbs before you draw it again.'");
    addResponseTopic("bow care", "How should I store a bow?",
        "choosing a bow");
    addResponse("arrows", "Can you repair a damaged arrow?",
        "@S@'Bring it here. A bent shaft should be replaced, not "
        "trusted in the field.'");
    addResponse("first conversation", "How should I practice?",
        "@S@'Start close to a clear target and focus on a smooth "
        "draw. Add distance only when your form stays steady.'");
    addResponseTopic("first conversation", "How should I practice?",
        "bow practice");
    addResponse("bow practice", "Can I practice in the woods?",
        "@S@'Only where you have permission and a safe backstop. "
        "Know who may cross your line before you shoot.'");
    addResponseTopic("bow practice", "Can I practice in the woods?",
        "arrows");
    addResponse("bow care", "What if the string looks worn?",
        "@S@'Stop using the bow and bring it in. A string can fail "
        "without warning, and a damaged limb is no safer.'");
    addResponseTopic("bow care", "What if the string looks worn?",
        "field repairs");
    addResponse("field repairs", "Can I mend it on the road?",
        "@S@'Carry a proper spare if you know how to fit one. If "
        "the limb is damaged, do not draw the bow until it is checked.'");
    addResponseTopic("field repairs",
        "Can I mend it on the road?", "bow care");
}
