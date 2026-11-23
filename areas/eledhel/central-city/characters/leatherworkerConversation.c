//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tavren sets down a leather "
        "harness and brushes the scraps from his hands. "
        "@S@'Welcome. Tell me what needs mending.'");
    addTopic("leather goods", "@S@'I keep practical leather goods "
        "and serviceable armor. A good fit matters more than a "
        "flashy buckle when the road turns rough.'");
    addTopic("repairs", "@S@'Bring me a sound piece with a worn "
        "strap or seam. If the leather itself is split through, "
        "a patch will not make it safe to trust.'");

    addResponse("first conversation", "What do you sell?",
        "@D@He gestures toward the shelves behind the counter.");
    addResponseTopic("first conversation", "What do you sell?",
        "leather goods");
    addResponse("first conversation", "Can you repair a harness?",
        "@D@Tavren checks the stitching on the harness in his hands.");
    addResponseTopic("first conversation", "Can you repair a harness?",
        "repairs");
}
