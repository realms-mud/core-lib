//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Dulin sets a crate on "
        "its corner and checks the rope around it. @S@'If you "
        "are looking for market goods, go through the gate. "
        "I keep the road supplies here so a broken lantern "
        "does not have to wait for a harbor ship.'");
    addTopic("the supplies", "@S@'Rope, lamp oil, canvas patches, "
        "and pitch for the small repairs. Nothing rare. The "
        "useful things are the ones that keep a cart from "
        "losing half its load before town.'");
    addTopic("the harbor", "@D@He nods toward Minlach's wall. "
        "@S@'The harbor crews use more line than most people "
        "expect. A snapped mooring rope is expensive; a frayed "
        "one that gets changed in time is not.'");
    addTopic("the lanterns", "@S@'The wall lamps and signal "
        "lanterns use different oil. The harbor light burns "
        "cleaner and longer. Mix the wrong supply and you "
        "get smoke when you need a clear signal.'");
    addTopic("the carts", "@D@Dulin tests the lid of a second "
        "crate. @S@'Every crate is marked for a person, not "
        "just a place. A load marked for Minlach can still "
        "belong to three different crews.'");
    addTopic("your work", "@S@'I used to keep a shopfront in "
        "the harbor quarter. Now I travel between the store "
        "and the road posts. The walls have more hands than "
        "they have room, and the road always needs one more rope.'");
    addTopic("your cousin", "@D@He glances toward the gate. "
        "@S@'My cousin works the chandlery inside Minlach. "
        "She says I am too careful with the stock. She says "
        "that right before she asks me to bring another crate.'");

    addResponse("first conversation", "What do you carry?",
        "@D@Dulin loosens the rope around the nearest crate. "
        "@S@'Lamp oil, coiled line, pitch, canvas, and spare "
        "hooks. The list is on the lid. Ask before you cut "
        "a seal; the harbor crew has to sign for every barrel.'");
    addResponseTopic("first conversation", "What do you carry?",
        "the supplies");
    addResponse("the supplies", "Can I use the harbor oil in a lamp?",
        "@D@He lifts the clean-burning flask for you to see. "
        "@S@'Not unless the lamp is meant for it. Signal oil "
        "burns hotter and longer. Use the ordinary flask for "
        "a room lantern.'");
    addResponseTopic("the supplies", "Can I use the harbor oil in a lamp?",
        "the lanterns");
    addResponse("first conversation", "Why keep supplies outside the wall?",
        "@D@Dulin pats the crate lid back into place. "
        "@S@'The wagons have room to turn here. The harbor "
        "street does not. It also keeps a late repair from "
        "blocking the gate.'");
    addResponseTopic("first conversation",
        "Why keep supplies outside the wall?", "the carts");
    addResponse("first conversation", "Do you work at the harbor?",
        "@D@He points through the gate with his chin. "
        "@S@'I bring stock to the crews. The shipwrights and "
        "lamp tenders order through my cousin, then I carry "
        "it from the road store.'");
    addResponseTopic("first conversation", "Do you work at the harbor?",
        "the harbor");
    addResponse("first conversation", "Why not keep a shop?",
        "@D@Dulin rubs the pale burn on his hand. @S@'I did. "
        "The road needs more of me now, and my cousin keeps "
        "the counter better than I did. She still claims I "
        "owe her for the shelves.'");
    addResponseTopic("first conversation", "Why not keep a shop?",
        "your work");
    addResponse("your cousin", "Do you get along?",
        "@D@His beard shifts with a restrained grin. "
        "@S@'Well enough to share a stock list. She knows "
        "which crews need rope; I know which loads arrive "
        "with the seals still intact.'");
}
