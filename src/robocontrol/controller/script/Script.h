/*
 * Script.h
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SCRIPT_H_
#define SCRIPT_H_

#include "instruction/parts/InstructionParts.h"
#include "ecrobot_interface.h"
#include "Common.h"
#include "Parameter.h"

namespace controller {

	/**
	 * プログラムデータを管理する
	 */
	class Script {
		instruction::parts::Instruction* m_begin; //!< プログラム開始位置
		instruction::parts::Instruction* m_end; //!< プログラム末尾の次のポインタ
		instruction::parts::Instruction* m_labelTabel[LABEL_COUNT]; //!< ラベルから命令ポインタを引くためのテーブル
		instruction::parts::Instruction* m_instructionPointer; //!< 現在の命令ポインタ
		Script();
	public:
		static Script & GetInstance();
		/**
		 * プログラム実行
		 * @note この関数は終了しない
		 */
		void Do();
		/**
		 * プログラムデータをセット
		 * @param begin プログラムデータの先頭ポインタ
		 * @param begin プログラムデータの末尾の次ポインタ
		 * @return 成功・失敗
		 */
		bool Set(instruction::parts::Instruction *begin, instruction::parts::Instruction * end);

		/**
		 * ラベルをセットする
		 * @param p
		 * @param label
		 */
		void SetLabel(instruction::parts::Instruction * p, LABEL label);

		/**
		 * ラベルから命令ポインタを取得する
		 * @param label
		 * @return 命令ポインタ
		 */
		instruction::parts::Instruction * GetInstructionPointer(LABEL label) const;

		/**
		 * 現在の命令ポインタを取得する
		 * @return 命令ポインタ
		 */
		instruction::parts::Instruction * GetInstructionPointer() const;

	};

} /* namespace controller */
#endif /* SCRIPT_H_ */
