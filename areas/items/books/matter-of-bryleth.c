//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights
// reserved. See the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "On the Matter of Bryleth");
    set("short", "A book titled 'On the Matter of Bryleth'");
    set("title", "On the Matter of Bryleth: A Heretical Inquiry");
    set("aliases", ({ "bryleth treatise", "heretical inquiry",
        "vain queen", "forbidden text", "book" }));
    set("long", "This text is marked with numerous corrections, "
        "erasures, and marginal warnings. It challenges the accepted "
        "account of Bryleth's capture, suggesting deeper and more "
        "dangerous truths. Several passages appear deliberately "
        "obscured, as though the author feared the implications.");

    addChapter("Chapter 1: Doubt",
        "The accepted account of Bryleth's binding is incomplete.\n"
        "This is not speculation, but conclusion drawn from absence.\n"
        "Too many records contradict. Too many witnesses fall silent.\n"
        "We are told she could not be slain.\n"
        "We are told she was bound at great cost.\n"
        "We are not told why she did not simply depart.\n"
        "A being of such power was not cornered like prey.\n"
        "Nor was she ignorant of the designs against her.\n"
        "The company sent to bind her was not concealed.\n"
        "Its members were known. Its purpose suspected.\n"
        "And yet she remained where they would find her.\n"
        "Waiting.\n"
        "This word appears in three independent fragments.\n"
        "Waiting is not the posture of the hunted.\n"
        "It is the posture of one who anticipates an outcome.\n"
        "If she waited, then the meeting was not chance.\n"
        "If not chance, then design.\n"
        "If design, then whose?\n"
        "We are left with a possibility few will accept.\n"
        "That Bryleth did not lose. She proceeded.");

    addChapter("Chapter 2: The Shape of the Ritual",
        "Fragments describe not a battle, but a structure.\n"
        "Positions taken. Words spoken. Actions repeated.\n"
        "The so-called binding bears marks of invocation.\n"
        "Not imprisonment alone, but transformation of state.\n"
        "The mages believed they were sealing her away.\n"
        "Yet their working required precise compliance.\n"
        "Timing. Placement. Sequence without deviation.\n"
        "Such rigidity invites exploitation.\n"
        "One account speaks of her correcting a gesture.\n"
        "Another of her laughing when a line was misplaced.\n"
        "If true, she guided the working to its completion.\n"
        "Not resisting, but ensuring success.\n"
        "Why?\n"
        "Because the prison was not merely a cage.\n"
        "It was a lock.\n"
        "And every lock implies a key.\n"
        "Not of metal, but of action.\n"
        "Action that must be repeated.\n"
        "Action that must be obeyed.\n"
        "This is the most troubling conclusion.\n"
        "The binding may have been the first half of a design.");

    addChapter("Chapter 3: On Obedience",
        "There are scattered references to trials.\n"
        "Not of strength, but of compliance.\n"
        "Instructions given. Steps followed without question.\n"
        "Blood offered where none was required.\n"
        "Doors opened only when sequence was honored.\n"
        "These are not defenses.\n"
        "They are filters.\n"
        "They do not keep intruders out.\n"
        "They ensure only the correct intruder proceeds.\n"
        "Consider the implication.\n"
        "The prison does not merely confine.\n"
        "It selects.\n"
        "It waits for one who will do as they are told.\n"
        "Without hesitation. Without deviation.\n"
        "One who will complete what was begun.\n"
        "The final act cannot be forced.\n"
        "It must be chosen.\n"
        "Chosen freely.\n"
        "This is not a safeguard.\n"
        "It is a mechanism.\n"
        "And mechanisms are built with purpose.");

    addChapter("Chapter 4: The Unspoken Name",
        "In older texts, her name is not Bryleth.\n"
        "That name appears only in later chronicles.\n"
        "Earlier fragments are damaged, or deliberately altered.\n"
        "Where a name should stand, there is absence.\n"
        "In one case, a symbol scratched out repeatedly.\n"
        "In another, a blank space preserved with care.\n"
        "This is not decay. It is removal.\n"
        "Why remove a name, yet preserve the warning?\n"
        "Unless the name itself holds power.\n"
        "Or recognition.\n"
        "One margin note, nearly erased, reads:\n"
        "She is not the queen. The queen is the mask.\n"
        "No author is given.\n"
        "No further explanation survives.\n"
        "If this is true, then Bryleth was never the whole.\n"
        "Only the shape she wore.\n"
        "And if the prison holds her still,\n"
        "it may not hold what we think it does.\n"
        "This text should have been destroyed.\n"
        "That it was not is itself a warning.");
}
