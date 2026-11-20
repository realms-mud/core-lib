//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Idel tests a repaired knot "
        "before turning to you. @S@'Mind the latch when you leave. "
        "The pasture is shared; the animals are not strays.'");
    addTopic("common beds", "@D@She points through the east door. "
        "@S@'South down the lane is the threshing yard. East of that "
        "are the public roots, with beans south beside the stream. "
        "Read the markers before you gather.'");
    addTopic("neighbors", "@S@'Nessa keeps the granary accounts. "
        "Torven minds the mill, and Pera takes produce to the road. "
        "A bad bridge or a wet grain sack costs all of us, not just "
        "the person carrying it.'");
    addTopic("woodland", "@D@Idel's hands stop on the rope. "
        "@S@'North of the orchard is the coppice. The old cart track "
        "continues beyond it. There are people camping off that "
        "track who do not ask permission before taking supplies. "
        "I keep the livestock this side of the boundary.'");
    addResponse("first conversation", "May I gather food here?",
        "@S@'At the marked common beds, when the crop is ready. "
        "Not from a tenant's unmarked field.'");
    addResponseTopic("first conversation", "May I gather food here?",
        "common beds");
    addResponse("first conversation", "Who works these farms?",
        "@S@'Several households. We share the mill and the stores, "
        "not every family's crop.'");
    addResponseTopic("first conversation", "Who works these farms?",
        "neighbors");
    addResponse("neighbors", "Can I buy provisions without gathering?",
        "@S@'Nessa sells stored produce in the granary south of "
        "this barn. Pera has a counter beside the west road.'");
    addResponse("common beds", "What is there in winter?",
        "@S@'Stubble and bare beds, mostly. Buy stored roots from "
        "Nessa or Pera; a snow-covered field is not a full larder.'");
    addResponse("first conversation", "What lies beyond the orchard?",
        "@S@'Managed trees first, then an old road we use less often.'");
    addResponseTopic("first conversation", "What lies beyond the orchard?",
        "woodland");
    addResponse("woodland", "Should I chase the people at the camp?",
        "@D@She shakes her head. @S@'Not on my say-so. Ask the city "
        "watch about the road, and do not mistake every traveler "
        "for a thief. I can tell you where I no longer take a cart.'");
    addResponse("woodland", "Is there a safer way to the produce stand?",
        "@S@'East out of the barn, north to the orchard edge, then "
        "east twice. There is no need to follow the old cart track.'");
}
