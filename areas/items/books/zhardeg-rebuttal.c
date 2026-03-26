//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "A Rebuttal to the Zhardeg Fragment");
    set("short", "A book titled 'Zhardeg Folly'");
    set("title",
        "A Rebuttal to the Zhardeg Fragment: On Power, Will, and Restraint");
    set("aliases",
        ({ "zhardeg rebuttal", "dhuras warning", "on restraint", "zhardeg folly",
            "book", "rebuttal" }));
    set("long",
        "A careful response composed by a later scholar of Dhuras, "
        "seeking to counter the reasoning found within the recovered "
        "Zhardeg fragment. Though measured in tone, the text reveals "
        "unease, as though the author struggles against arguments "
        "that cannot be easily dismissed.");

    addChapter("On the Claim That Power Reveals",
        "The fragment asserts that power reveals, but does not corrupt.\n"
        "This is an appealing distinction, and not wholly false.\n"
        "Yet it omits a critical truth.\n"
        "Revelation without restraint is indistinguishable from corruption.\n"
        "If a fracture is revealed and then indulged, what is that but decay?\n"
        "The fragment names the unbroken as fit to wield power.\n"
        "But who shall name such a one?\n"
        "Each man believes himself sufficient, until proven otherwise.\n"
        "And by then, the cost is seldom his alone.\n");

    addChapter("On the Denial of Enemies",
        "To name all opposition as mere impediment is a subtle error.\n"
        "It removes intent from the world, and with it, responsibility.\n"
        "A beast may act without malice, yet still must be opposed.\n"
        "To oppose is not hatred, but judgment.\n"
        "If all things are permitted their nature without question,\n"
        "then cruelty is granted equal standing with mercy.\n"
        "The fragment calls this alignment.\n"
        "We name it abdication.\n");

    addChapter("On the Voice That Does Not Speak",
        "Here lies the most insidious portion of the text.\n"
        "It claims no command, no domination of will.\n"
        "Only arrangement. Only inevitability.\n"
        "Thus the reader is disarmed.\n"
        "For what cannot be argued cannot be resisted.\n"
        "If every thought remains 'one's own', who then is to blame?\n"
        "This is the danger: not compulsion, but permission.\n"
        "The fragment does not seize the will.\n"
        "It absolves it.\n");

    addChapter("On the Use of the Dead",
        "The argument presented is one of efficiency.\n"
        "What is unused is waste; what is restored is strength.\n"
        "Such reasoning is not without precedent in lesser matters.\n"
        "But here it is extended beyond all rightful boundary.\n"
        "The dead are not merely absence of motion.\n"
        "They are the conclusion of a life, and must remain so.\n"
        "To deny this is to deny the meaning of life itself.\n"
        "If a man may be reduced to function, then so may the living.\n"
        "This road does not end where the fragment suggests.\n");

    addChapter("On Sufficiency",
        "The fragment speaks of a threshold beyond which resistance fails.\n"
        "It calls this sufficiency, and strips it of moral weight.\n"
        "Yet sufficiency without boundary is indistinguishable from excess.\n"
        "The claim that 'enough' may be known is itself suspect.\n"
        "For each victory redefines what is required.\n"
        "Thus the threshold recedes as one approaches it.\n"
        "What begins as necessity becomes expansion.\n"
        "What becomes expansion rarely returns to restraint.\n");

    addChapter("On the Dragon as Measure",
        "We are told that the dragon is a measure.\n"
        "That failure marks insufficiency, and success demands change.\n"
        "This is perhaps the most dangerous proposition of all.\n"
        "For it binds worth to victory, and virtue to transformation.\n"
        "If one must become other to prevail, what has been preserved?\n"
        "A victory that erases the victor is not triumph.\n"
        "It is replacement.\n"
        "And what stands in place of the fallen self may not be better.\n");

    addChapter("On Argloth",
        "We must speak plainly, though it brings us shame.\n"
        "Argloth did not begin as a fool or tyrant.\n"
        "He followed the logic where it led.\n"
        "Each step was reasoned, each act justified.\n"
        "He sought sufficiency against a terror we could not face.\n"
        "And he achieved it.\n"
        "Let no one claim he failed in that aim.\n"
        "But in doing so, he became the argument made manifest.\n"
        "This is the proof the fragment does not provide.\n");

    addChapter("Conclusion",
        "The fragment is not to be dismissed as madness.\n"
        "It is coherent, persuasive, and dangerously incomplete.\n"
        "It speaks truth, but not the whole of it.\n"
        "And in that absence, it misleads.\n"
        "We therefore preserve it, but do not teach it unguarded.\n"
        "Let it be studied with caution, and never in isolation.\n"
        "For even now, I find its reasoning returns to me unbidden.\n"
        "And I am no longer certain where my thoughts end, and it begins.\n"
        "[A final note: 'Seal the lower vaults again.']\n");
}
