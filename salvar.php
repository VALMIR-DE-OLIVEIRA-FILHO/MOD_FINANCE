<?php
require_once "classes/LancamentoManager.php";

$manager = new LancamentoManager("data/lancamentos.txt");

$lista = $manager->listar();
$id = count($lista) + 1;

$l = new Lancamento(
    $id,
    $_POST["descricao"],
    $_POST["valor"],
    $_POST["tipo"],
    $_POST["data"]
);

$manager->adicionar($l);

header("Location: index.php");
exit;
