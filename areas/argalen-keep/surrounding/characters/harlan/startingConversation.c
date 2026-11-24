//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Harlan wipes his hands on a "
        "work cloth before greeting you. @S@'If you came for a quiet "
        "walk, keep to the lane. The field drain is soft after rain, "
        "and I have spent enough mornings pulling carts out of it.'");
    addTopic("the farm", "@D@Harlan nods toward the house, the barn, "
        "and the narrow channels between the fields. @S@'This holding "
        "feeds a few households, not an army. We mend tools, keep the "
        "animals sound, and share the work when weather turns against us.'");
    addTopic("the western track", "@D@He closes his account book and "
        "looks toward the trees. @S@'I saw two unfamiliar carts take "
        "the old track after dusk this week. They did not stop to buy "
        "grain, and they came back lighter than they went. I told "
        "Galadhel what I saw. I will not call anyone a thief without "
        "knowing what was carried.'");
    addTopic("the drain", "@D@Harlan crouches beside the channel and "
        "checks a small stone weir with his boot. @S@'A field is only "
        "as good as its water. Clear this before the spring rain, or "
        "the road gets the soil and the crop gets the stones.'");
    addRepeatableTopic("default", "@D@Harlan turns back to his work. "
        "@S@'I have a rail to set and a gate to check before noon. "
        "Ask what you need, but mind the wet ground.'");

    addResponse("first conversation", "How is life on the farm?",
        "@D@You ask what the work here is like through the year.");
    addResponseTopic("first conversation", "How is life on the farm?",
        "the farm");
    addResponse("first conversation", "Have you noticed anything unusual?",
        "@D@You ask about the travelers on the western road.");
    addResponseTopic("first conversation",
        "Have you noticed anything unusual?", "the western track");
    addResponse("first conversation", "What are you mending?",
        "@D@You ask about the channel running beside the field.");
    addResponseTopic("first conversation", "What are you mending?",
        "the drain");

    addResponse("the farm", "Do you own the land?",
        "@D@Harlan shakes his head. @S@'The keep holds the land. "
        "We hold the tenancy and the work that goes with it. A fair "
        "harvest keeps both sides fed; a bad one means hard talks.'");
    addResponse("the farm", "What do the carts have to do with you?",
        "@D@Harlan glances toward the field gate. @S@'They used the "
        "same track as our deliveries. I want to know whether the "
        "road is safe, not decide who belongs on it.'");
    addResponseTopic("the farm", "What do the carts have to do with you?",
        "the western track");
    addResponse("the western track", "Can I follow them?",
        "@S@'Not alone, and not after dark. Speak with Galadhel and "
        "Halgaladh at the keep. They know the old ruins better than I do.'");
    addResponseTopic("the western track", "Can I follow them?",
        "the farm");
    addResponse("the drain", "Why not send someone from the keep?",
        "@S@'Because this is ordinary work, and we can do it ourselves. "
        "The keep has enough to watch without guarding every furrow.'");
    addResponse("default", "What did you see on the west track?",
        "@D@You ask Harlan to describe the carts he saw.");
    addResponseTopic("default", "What did you see on the west track?",
        "the western track");
    addResponse("default", "Show me how the drain works.",
        "@D@You ask Harlan to explain the field channel.");
    addResponseTopic("default", "Show me how the drain works.",
        "the drain");
}
