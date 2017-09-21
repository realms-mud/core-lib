virtual inherit "/lib/modules/research/passiveResearchItem.c";

public void reset(int arg)
{
    if (!arg)
    {
        "passiveResearchItem"::reset(arg);
        addSpecification("name", "mock research");
        addSpecification("description", "This does stuff.");
        addSpecification("scope", "self");
        addSpecification("research type", "timed");
        addSpecification("research cost", 10);
        addSpecification("bonus strength", 1);
        addSpecification("bonus weapon attack", 1); // Don't care about the value
        addSpecification("bonus fire attack", 25);  // value is the damage if not a
                                                    // weapon attack
    }
}


