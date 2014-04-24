#ifndef GT_GTL_SCANNER_HPP_INCLUDED
#define GT_GTL_SCANNER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/scanner.hpp
 * @brief     Defines GT::GTL::Scanner class.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @cond Doxygen_Suppress */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Makes ::GTLFLexLexer visible to Scanner.
 *
 * Similar code is executed inside scanner.cpp generated with Flex - code in if instuction is repeated,
 * so that other classes (Scanner in particular) would see see ::GTLFlexLexer.
 */
#ifndef GTL_FLEX_LEXER_DEFINED
#    define  GTL_FLEX_LEXER_DEFINED
#    undef   yyFlexLexer
#    define  yyFlexLexer GTLFlexLexer
#    include <FlexLexer.h>
#    undef   yyFlexLexer
#endif /* END #ifndef GTL_FLEX_LEXER_DEFINED */

/**
 * @brief Makes Scanner::lex() function signature of generated main scanning function.
 */
#undef  YY_DECL
#define YY_DECL int GT::GTL::Scanner::lex()

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Scanner
 * @brief Scans for tokens declared by Parser class in given InputStream.
 *
 * Its content is generated by Flex (Lex?) from scanner.yy class. Acts as a more convinient wrapper for
 * GTLFlexLexer.
 *
 * @author Mateusz Kubuszok
 *
 * @see Parser
 * @see ::GTLFlexLexer
 */
class Scanner : public GTLFlexLexer {
    /**
     * @brief Field used during token scanning - contains actual value of parsed chain.
     */
    Parser::semantic_type* lval;

public:
    /**
     * @brief Initiates Scanner with input stream that serves as data source.
     *
     * @param inputStream input stream initiating Scanner
     */
    explicit Scanner(
        InputStream* inputStream
    );

    /**
     * @brief Whether scanner is currently interactive.
     *
     * @return true if current buffer is set and it's interactive
     */
    bool isInteractive() const;

    /**
     * @brief Set whether scanner should be interactive or not.
     *
     * Interactive scanner behaves better (?) in a console but is slower than non-interactive one.
     *
     * @param isInteractive true if scanner should be interactive
     */
    void setInteractive(
        bool isInteractive
    );

    /**
     * @brief Scans for next token.
     *
     * @param newlval     initiates next scanning with value
     * @param newlocation location to fill with positions
     * @return            returns number of next token
     */
    virtual int lex(
        Parser::semantic_type* newlval,
        Parser::location_type& newlocation
    );

private:
    /**
     * @brief Actual lexer/scanner function.
     *
     * Uses source defined by the constructor. Its body is generated from scanner.yy file by Flex with
     * YY_DECL macroinstruction.
     *
     * @return value used for communicating with Parser
     */
    int lex();
}; /* END class Scanner */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

/** @endcond */


#endif /* END #ifndef GT_GTL_SCANNER_HPP_INCLUDED */
