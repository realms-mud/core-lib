//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trademaster interior");

    addItemTemplate(
        "The trademaster's office is a well-appointed room designed for "
        "commerce. A broad oak desk dominates the center, its surface "
        "covered with ledgers, contracts, and a heavy brass abacus. A large "
        "slate board on one wall lists commodity prices in chalk - grain, "
        "hides, ore, timber, and cloth - with figures updated in a neat "
        "hand. Locked cabinets line the back wall, their iron hasps hinting "
        "at valuable stores within. A set of merchant's scales sits on the "
        "counter, beside a strongbox and a carved wooden rack holding trade "
        "seals and wax. The room smells of ink, sealing wax, and old paper."
    );

    addNearDarkDescriptionTemplate(
        "the trademaster's office is dark, the desk and its ledgers "
        "swallowed by shadow and the chalk board unreadable"
    );
    addLowLightDescriptionTemplate(
        "the trademaster's desk is a dim shape in the gloom, the locked "
        "cabinets along the back wall barely visible"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the broad desk, the abacus, and the slate "
        "board with its columns of chalked figures"
    );
    addSomeLightDescriptionTemplate(
        "the trademaster's office is bright enough to read the commodity "
        "prices on the board and the spines of the ledgers"
    );
    addDescriptionTemplate(
        "light fills the trademaster's office, making the brass abacus "
        "gleam and the chalked figures on the slate board crisp and clear"
    );
}
