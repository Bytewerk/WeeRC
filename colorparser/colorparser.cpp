#include <iostream>
#include <string>

#define CHECK_FOR_PREFIX 0
#define PARSE_COLOR_CODE 1
#define SET_ATTRIBUTE 2
#define REMOVE_ATTRIBUTE 3
#define RESET 4

using namespace std;

class Color {
	public:
		static string getRgbByWeechatColorCode( string weechatColorCode ) {
			if ( weechatColorCode == "00" ) {
				return "initial";
			} else if ( weechatColorCode == "01" ) {
				return "black";
			} else if ( weechatColorCode == "02" ) {
				return "#424242";
			} else if ( weechatColorCode == "03" ) {
				return "#420000";
			} else if ( weechatColorCode == "04" ) {
				return "#FF4242";
			} else if ( weechatColorCode == "05" ) {
				return "#42FF42";
			} else if ( weechatColorCode == "06" ) {
				return "#004200";
			} else if ( weechatColorCode == "07" ) {
				return "brown";
			} else if ( weechatColorCode == "08" ) {
				return "yellow";
			} else if ( weechatColorCode == "09" ) {
				return "#FFFF42";
			} else if ( weechatColorCode == "10" ) {
				return "#000042";
			} else if ( weechatColorCode == "11" ) {
				return "#420042";
			} else if ( weechatColorCode == "12" ) {
				return "#FF42FF";
			} else if ( weechatColorCode == "13" ) {
				return "#004242";
			} else if ( weechatColorCode == "14" ) {
				return "#42FFFF";
			} else if ( weechatColorCode == "15" ) {
				return "grey";
			} else if ( weechatColorCode == "16" ) {
				return "#FFFFFF";
			} else {
				return "-1";
			}
		}
};

class FormattedSpan {
	private:
		string m_formattedSpanString = "";
		string m_foregroundColor = "";
		string m_backgroundColor = "";
		string m_text = "";
		bool m_bold = false;
		bool m_reverse = false;
		bool m_italic = false;
		bool m_underline = false;
		bool m_isForegroundColorChanged = false;

	public:
		FormattedSpan( string text = "", string foregroundColor = "", string backgroundColor = "", bool bold = false, bool reverse = false, bool italic = false, bool underline = false )  {
			this->m_text = text;
			this->m_backgroundColor = backgroundColor;
			this->m_foregroundColor = foregroundColor;
			this->m_bold = bold;
			this->m_reverse = reverse;
			this->m_italic = italic;
			this->m_underline = underline;
		}

		void appendChar( char charToAppend ) {
			this->m_text += charToAppend;
		}

		bool isForegroundColorChanged() {
			return this->m_isForegroundColorChanged;
		}

		void setText( string text ) {
			this->m_text = text;
		}

		void setBackgroundColor( string backgroundColor ) {
			if (backgroundColor != "-1") {
				this->m_backgroundColor = backgroundColor;
			}
		}

		void setForegroundColor( string foregroundColor ) {
			if (foregroundColor != "-1") {
				this->m_foregroundColor = foregroundColor;
				this->m_isForegroundColorChanged = true;
			}
		}

		void setBold( bool bold ) {
		 this->m_bold = bold;
		}

		void setReverse( bool reverse ) {
			this->m_reverse = reverse;
		}

		void setItalic( bool italic ) {
			this->m_italic = italic;
		}

		void setUnderline( bool underline ) {
			this->m_underline = underline;
		}

		string getText() {
			return this->m_text;
		}

		string getBackgroundColor() {
			return this->m_backgroundColor;
		}

		string getForegroundColor() {
			return this->m_foregroundColor;
		}

		bool getBold() {
			return this->m_bold;
		}

		bool getReverse() {
			return this->m_reverse;
		}

		bool getItalic() {
			return this->m_italic;
		}

		bool getUnderline() {
			return this->m_underline;
		}

		string genFormattedSpan() {
			this->m_formattedSpanString = string("<span style=\"") +
				(this->m_bold ? string("font-weight: bold; ") : string("font-weight: initial; ")) +
				(this->m_italic ? string("font-style: italic; ") : string("font-style: initial; ")) +
				(this->m_underline ? string("text-decoration: underline; ") : string("text-decoration: initial; ")) +
				(this->m_foregroundColor != "" ? string("color: ") + m_foregroundColor + string("; ") : string("color: initial; ")) +
				(this->m_backgroundColor != "" ? string("background-color: ") + m_backgroundColor + string("; ") : string("background-color: initial; ")) +
				(this->m_reverse ? string() : string()) +
				string("\">") + this->m_text + "</span>";
			return m_formattedSpanString;
		}
};

int main () {
	string lineInput;
	getline(cin, lineInput);
	int state = CHECK_FOR_PREFIX;
	string formattedString = "";
	string colorCode = "";

	FormattedSpan* lastSpan = new FormattedSpan();
	//cout << lastSpan->genFormattedSpan();

	for ( int i = 0; i < lineInput.size(); i++ ) {
		switch ( state ) {
			case ( CHECK_FOR_PREFIX ):
				switch ( (int) lineInput[i] ) {
					case (int) 0x19:
						state = PARSE_COLOR_CODE;
						break;
					case (int) 0x1a:
						state = SET_ATTRIBUTE;
						break;
					case (int) 0x1b:
						state = REMOVE_ATTRIBUTE;
						break;
					case (int) 0x1c:
						state = RESET;
						break;
					default:
						// if none of the above matches, it should be text that is going to be displayed
						lastSpan->appendChar(lineInput[i]);
						break;
				}
				break;
			case ( PARSE_COLOR_CODE ):
				switch ( (int) lineInput[i] ) {
					case (int) '@': //EXT
						i += 2;
						for ( int colorCodeCounter = 0; colorCodeCounter < 5; colorCodeCounter++ ) {
							colorCode += lineInput[i];
							i++;
						}
						colorCode = "";
						state = CHECK_FOR_PREFIX;
						break;
					case (int) 'F':
						i++; //skip over the colorprefix (F)
						for (int colorCodeCounter = 0; colorCodeCounter < 2; colorCodeCounter++) {
							colorCode += lineInput[i];
							i++;
						}
						i--; //prevent double increment from next loop
						if ( lastSpan->isForegroundColorChanged() ) {
							formattedString += lastSpan->genFormattedSpan();
							delete( lastSpan );
							lastSpan = new FormattedSpan();
							lastSpan->setForegroundColor(Color::getRgbByWeechatColorCode(colorCode));
						} else {
							lastSpan->setForegroundColor(Color::getRgbByWeechatColorCode(colorCode));
						}
						colorCode = "";
						state = CHECK_FOR_PREFIX;
						break;
					case (int) 'B':
						break;
					case (int) '*':
						break;
					case (int) 'b': //bar and input bar format
						i++; // we just ignore this
						break;
					case (int) 'E':
						break;
					case (int) 0x1c:
						break;
					default: //STD
						for ( int colorCodeCounter = 0; colorCodeCounter < 2; colorCodeCounter++ ) {
							colorCode += lineInput[i];
							i++;
						}
						i--; //prevent double increment from next loop
						if ( lastSpan->isForegroundColorChanged() ) {
							formattedString += lastSpan->genFormattedSpan();
							delete( lastSpan );
							lastSpan = new FormattedSpan();
							lastSpan->setForegroundColor(Color::getRgbByWeechatColorCode(colorCode));
						} else {
							lastSpan->setForegroundColor(Color::getRgbByWeechatColorCode(colorCode));
						}
						colorCode = "";
						state = CHECK_FOR_PREFIX;
						break;
				}
				break;
			case ( SET_ATTRIBUTE ):
				switch ( (int) lineInput[i] ) {
					case (int) '*': // bold
						lastSpan->setBold(true);
						break;
					case (int) '!': // reverse
						lastSpan->setReverse(true);
						break;
					case (int) '/': // italic
						lastSpan->setItalic(true);
						break;
					case (int) '_': // underline
						lastSpan->setItalic(true);
						break;
					case (int) '|': // keep attributes <- wtf oO?
						break;
				}
				break;
			case ( REMOVE_ATTRIBUTE ):
				switch ( (int) lineInput[i] ) {
					case (int) '*': // bold
						lastSpan->setBold(false);
						break;
					case (int) '!': // reverse
						lastSpan->setReverse(false);
						break;
					case (int) '/': // italic
						lastSpan->setItalic(false);
						break;
					case (int) '_': // underline
						lastSpan->setUnderline(false);
						break;
					case (int) '|': // keep attributes <- wtf oO?
						break;
				}
				break;
			case ( RESET ):
				//TODO: Reset attributes and color
				state = CHECK_FOR_PREFIX;
				break;
			default:
				// undefined state of the statemachine
				// this should never happen
				break;
		}
	}
	
	//cout << lastSpan->genFormattedSpan();
	formattedString += lastSpan->genFormattedSpan();
	cout << formattedString << "<br/>";
	return 0;
}
