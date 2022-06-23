/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:30:23 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 08:30:23 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
シミュレーションのルール
	・一人または複数の哲学者が円卓に座っているとする。
	・哲学者たちが同時に持つ状態は必ず1つ(食事、思考、睡眠)
	・テーブルには哲学者の数のフォークがある。
	・哲学者は食事をするときに2本のフォークを使う
	・哲学者は食事を終えると、フォークをテーブルに戻し眠り始める。
		そして哲学者は目が覚めると思考を開始する。
	・シミュレーションは哲学者が餓死した時点で停止する。

	・すべての哲学者は可能な限り食事をし、飢えてはいけない。
	・哲学者は他人に食事を譲ったりしてはいけない(常にルールベースで行動するべき？)

プログラムのルール
	・グローバル変数禁止
	・引数は
		・哲学者の数,またフォークの数
		・哲学者が食事が出来ないとき、死ぬまでの時間(ミリ秒)
		・哲学者が食事にかかる時間、この間哲学者はフォークを2本持つ必要がある(ミリ秒)
		・哲学者が一度の睡眠にかかる時間(ミリ秒)
		・すべての哲学者がこの食事回数を終えたら終了(引数を渡すかは任意)

	・すべての哲学者は1から順番に数が割り当てられている。
	・すべての哲学者は連番で隣に座る必要がある。

	・哲学者の状態が変更された時以下の出力をする必要がある。
			※timestamp_in_msは時間、Xは哲学者の番号
		・フォークをとったとき
			timestamp_in_ms X has taken a fork
		・食事を開始したとき
			timestamp_in_ms X is eating
		・睡眠を開始したとき
			timestamp_in_ms X is sleeping
		・思考を開始したとき
			timestamp_in_ms X is thinking
		・死亡したとき
			timestamp_in_ms X died
	・また、これらのメッセージは他のメッセージと混ざったりしてはいけない。
		(処理はそれぞれ完了させてくださいってこと？)
	・哲学者が死んだときは、実際に死んでから10ミリ秒以内に表示する。
	・哲学者は可能な限り死なないように。

	・プログラムはデータレース状態になってはいけない。
		すべて同時に実行しようとして順番と行動に矛盾が発生してはいけない。
*/

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_arguments	arg;

	arg = new_arg();
	if (parse_arg(argc, argv, &arg) != 0)
		return (1);
	show_arg(arg);
}
